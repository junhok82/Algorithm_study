#include <iostream>
#include <vector>
using namespace std;

class graph
{
	public :
		int node;
		vector<vector<int>> edge;
		vector<bool> visited;

		graph() : node(0) {}
		graph(const int& n) : node(n) {
			visited.resize(n);
			edge.resize(n);
		}

		void addEdge(const int& u, const int& v) { edge[u].push_back(v); }

		bool DFS(const int& curr, const int& value)
		{
			visited[curr] = true;
			for(int next : edge[curr])
			{
				if(next == value)
					return true;
				else if(!visited[next])
					if(DFS(next,value))
						return true;
			}
			return false;
		}
};

int main()
{
	int size;
	scanf("%d", &size);

	int input;
	graph G(size);
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
		{
			scanf("%d", &input);
			if(input == 1)
				G.addEdge(i,j);
		}

	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			fill(G.visited.begin(), G.visited.end(), false);
			printf("%d ", G.DFS(i,j) ? 1 : 0); 
		}
		printf("\n");
	}

	return 0;
}
