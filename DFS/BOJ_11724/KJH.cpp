nclude <iostream>
#include <vector>
using namespace std;

class Graph
{
	public :
		int node;
		vector<vector<int>> adj;
		vector<bool> visited;

		Graph() : node(0) {}
		Graph(int n) : node(n) {
						adj.resize(node);
						visited.resize(node,false);
		}

		void AddEdge(const int& u, const int& v)
		{
						adj[u].push_back(v);
						adj[v].push_back(u);
		}

		// Explore one component
		void Dfs(const int& curr)
		{
			visited[curr] = true;

			// Explore all nodes
			for(int next : adj[curr])
							if(!visited[next])
											Dfs(next);
		}

		int AllDfs()
		{
			int component = 0;
			// Explore all components
			for(int i = 0; i < node; i++)
				if(!visited[i])
				{
								component++;
								Dfs(i);
				}
			return component;
	}
};

int main()
{
	int nodes, edge;
	scanf("%d %d", &nodes, &edge);

	Graph G(nodes);

  for(int i = 0; i < edge; i++)
  {
			int u,v;
			scanf("%d %d", &u, &v);
			G.AddEdge(u-1,v-1);
	}

	cout << G.AllDfs();

	return 0;
}
