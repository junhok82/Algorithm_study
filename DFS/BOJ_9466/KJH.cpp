#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class graph
{
	public :
		int node, belong;
		vector<int> adj;
		vector<pair<bool,bool>> state;	// visited,finished

		graph(const int& n) : node(n), belong(0) {
			adj.reserve(node);
			state.resize(node,make_pair(false,false));
		}
		
		void DFS()
		{
			for(int i = 0; i < node; i++)
				if(!state[i].first)
					DFS(i);
		}

	private :
		void DFS(const int& curr)
		{
			const int next = adj[curr];
			state[curr].first = true;

			if(state[next].first)		//	visited
			{
				if(!state[next].second)	// not finished
				{
					for(int temp = next; temp != curr; temp = adj[temp])
						belong++;
					belong++;
				}
			}
			else										 //	not visited
				DFS(next);
			state[curr].second = true;
		}
};

int main()
{
	int test_case;
	scanf("%d", &test_case);

	vector<int> result(test_case);

	for(int i = 0; i < test_case; i++)
	{
		int n;
		scanf("%d", &n);

		graph G(n);
		int input;
		for(int j = 0; j < n; j++)
		{
			scanf("%d", &input);
			G.adj.push_back(input - 1);
		}

		G.DFS();
		result[i] = n - G.belong;
	}

	for(int i = 0; i < test_case; i++)
		printf("%d\n", result[i]);

	return 0;
}

