//i->j
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

bool table[101][101] = { 0, };
int num;

class Graph {
public:
	int N;
	vector<vector<int>> adj;

	Graph() :N(0) {}
	Graph(int n) :N(n) {
		adj.resize(n);
	}

	void addEdge(int u, int v) {
		adj[u].push_back(v);
	}

	void makeTable() {
		for (int i = 0; i < num; i++) {
			if (adj[i].size() != 0) {
				for (int next : adj[i]) {
					dfs(i, next);
				}
			}
		}
	}

private:
	void dfs(int start, int curr) {
		if (table[start][curr]) return;
		else table[start][curr] = true;

		for (int next : adj[curr]) {
			dfs(start, next);
		}
	}

};

int main() {
	scanf("%d", &num);
	Graph g(num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			int ij;
			scanf("%d", &ij);
			if (ij != 0)	g.addEdge(i, j);
		}
	}
	g.makeTable();

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			printf("%d ", table[i][j]);
		}printf("\n");
	}

}