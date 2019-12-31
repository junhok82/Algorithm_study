#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

class Graph {
public :
	int N;
	vector<vector<int>> adj;
	vector<bool> visited;

	Graph() :N(0) {};
	Graph(int n) :N(n) {
		adj.resize(n);
		visited.resize(n);
	}

	void addEdge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void sortList() {
		for (int i = 0; i < N; i++) sort(adj[i].begin(), adj[i].end());
	}

	int dfs() {
		fill(visited.begin(), visited.end(), false);
		int component = 0;
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				dfs(i);
				component++;
			}
		}
		return component;
	}
private:
	void dfs(int curr) {
		visited[curr] = true;
		for (int next : adj[curr]) {
			if (!visited[next]) {
				dfs(next);
			}
		}
	}
};

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	Graph G(N);
	for (int i = 0; i < M; i++) {
		int v, u;
		scanf("%d %d", &v, &u);
		G.addEdge(v-1, u-1);
	}
	G.sortList();
	printf("%d\n",G.dfs());

	return 0;
}
