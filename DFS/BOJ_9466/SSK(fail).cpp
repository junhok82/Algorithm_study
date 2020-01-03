#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

class Graph {
public:
	int N;
	vector<vector<int>> adj;
	vector<bool> visited;
	vector<int> team_complete;
	Graph() : N(0) {}
	Graph(int n) :N(n) {
		adj.resize(n);
		visited.resize(n);
	}
	void addEdge(int v, int u) {
		adj[v].push_back(u);
	}

	void dfs() {
		for (int i = 0; i < N; i++) {
			bool check = false;
			for (int completeIndex : team_complete) {
				if (completeIndex == i) {
					check = true;
					break;
				}
			}
			if (check) continue;
			fill(visited.begin(), visited.end(),false);
			int count = 0;
			if (dfs(i, count) != i) {
				for (int j = 0; j < count; j++) team_complete.pop_back();
			}
		}
	}

private:
	int dfs(int curr,int &count) {
		count++;
		visited[curr] = true;
		team_complete.push_back(curr);
		if(!visited[adj[curr][0]]) return dfs(adj[curr][0],count);
		else {
			return adj[curr][0];
		}

	}

};

int main() {
	int T,n;
	scanf("%d\n", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		Graph G(n);
		for (int j = 0; j < n; j++) {
			int temp;
			scanf("%d", &temp);
			G.addEdge(j, temp-1);
		}
		G.dfs();
		
		printf("%d\n", n - G.team_complete.size());
	}

	

	return 0;
}