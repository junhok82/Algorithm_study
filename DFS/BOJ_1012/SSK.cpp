#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

class graph {
public:
	int n;
	vector<vector<int>> adj;
	vector<bool> visited;

	graph() :n(0) {};
	graph(int n) : n(n) {
		adj.resize(n);
		visited.resize(n);
	}

	void addedge(int u,int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void sortlist() {
		for (int i = 0; i < n; i++) {
			sort(adj[i].begin(), adj[i].end());
		}
	}

	int dfs() {
		int component = 0;
		fill(visited.begin(), visited.end(), false);
		for (int i = 0; i < n; i++) {
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
	int t;
	int m,n,k;
	vector<vector<int>> parm;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d %d", &m, &n, &k);
		parm.resize(n);
		for (int j = 0; j < n; j++) {
			parm[j].resize(m);
			for (int z = 0; z < m; z++) {
				parm[j][z] = -1;
			}
		}
		graph g(k);
		g.sortlist();
		for (int j = 0; j < k; j++) {
			int a,b;
			scanf("%d %d", &a, &b);
			parm[b][a] = j;
			if (b >= 1) {
				if (parm[b - 1][a]!=-1) {
					g.addedge(parm[b][a], parm[b - 1][a]);
				}
			}
			if (a >= 1) {
				if (parm[b][a-1] != -1) {
					g.addedge(parm[b][a], parm[b][a-1]);
				}
			}

		}
		printf("%d\n",g.dfs());
	}


	return 0;
}