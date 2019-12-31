#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
int maxCount = 0;
class Graph {
public:
	int N;
	vector<vector<int>> adj;
	vector<bool> visited;

	Graph() :N(0) {}
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

	void dfs() {
		fill(visited.begin(), visited.end(), false);
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				int count = 0;
				dfs(i,count);
				maxCount = (maxCount < count) ? count : maxCount;
			}
		}
	}
private:
	void dfs(int curr,int &count) {
		count++;
		visited[curr] = true;
		for (int next : adj[curr]) {
			if (!visited[next]) {
				dfs(next, count);
			}
		}
	}
};

int main() {
	int N, M,K;
	int **hallway;

	scanf("%d %d %d", &N, &M, &K);
	hallway = new int*[N];
	for (int i = 0; i < N; i++) {
		hallway[i] = new int[M];
		for (int j = 0; j < M; j++) {
			hallway[i][j] = -1;
		}
	}
	Graph G(K);

	for (int i = 0; i < K; i++) {
		int r, c;
		scanf("%d %d", &r, &c);
		hallway[r-1][c-1] = i;
		
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (hallway[i][j] != -1) {
				if (j >= 1 && hallway[i][j - 1] != -1) {
					G.addEdge(hallway[i][j], hallway[i][j - 1]);
				}
				if (i >= 1 && hallway[i - 1][j] != -1) {
					G.addEdge(hallway[i][j], hallway[i - 1][j]);
				}
			}
		}
	}
	G.sortList();
	G.dfs();


	printf("%d\n", maxCount);

	return 0;
}