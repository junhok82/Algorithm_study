#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
class Graph {
public:
	int N;
	vector<vector<int>> adj;
	vector<bool> visited;
	vector<int> component;

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
				dfs(i, count);
				component.push_back(count);
			}
		}
	}
private:
	void dfs(int curr, int &count) {
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
	int N;
	int map[25][25] = { 0, };
	int houseCount = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		char *row = new char[N + 1];
		scanf("%s", row);
		for (int j = 0; j < N; j++) {
			if (row[j] == '0') map[i][j] = -1;
			if (row[j] == '1') {
				map[i][j] = houseCount;
				houseCount++;
			}
			
		}
	}
	
	Graph G(houseCount);

	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j]!=-1) {
				if (j >= 1 && map[i][j - 1]!=-1) {
					G.addEdge(map[i][j], map[i][j - 1]);
				}
				if (i >= 1 && map[i - 1][j] != -1) {
					G.addEdge(map[i][j], map[i - 1][j]);
				}
			}
		}
	}
	G.sortList();
	G.dfs();

	sort(G.component.begin(), G.component.end());
	printf("%d\n", G.component.size());
	for (int i = 0; i < G.component.size(); i++) {
		printf("%d\n",G.component[i]);
	}

	return 0;
}