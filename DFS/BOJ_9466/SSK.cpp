#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

class Graph {
public:
	int N;
	vector<int> adj;
	vector<int> visited;

	Graph() : N(0) {}
	Graph(int n) :N(n) {
		visited.resize(n);
	}
	void addEdge(int u) {
		adj.push_back(u);
	}

	void dfs() {
		fill(visited.begin(), visited.end(), 0);
		for (int i = 0; i < N; i++) {
			if (visited[i]==0) {
				dfs(i,i+1);;
			}
			
		}
	}

private:
	void dfs(int curr,int startIndex) {
		visited[curr] = startIndex;
		if (visited[adj[curr]]==0) {
			dfs(adj[curr], startIndex);
		}
		else {
			if(visited[adj[curr]] == startIndex)
			checkReapeat(adj[curr]);
		}
	}
	void checkReapeat(int curr) {
		if (visited[curr] < 1000000) {
			visited[curr] += 1000000;
			checkReapeat(adj[curr]);
		}
	}

};

int main() {
	int T, n;
	scanf("%d\n", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		Graph G(n);
		for (int j = 0; j < n; j++) {
			int temp;
			scanf("%d", &temp);
			G.addEdge(temp - 1);
		}
		G.dfs();
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (G.visited[j] <=1000000) count++;
		}
		printf("%d\n",count);
		for (int j = 0; j < n; j++) {
			printf("visited[%d] = %d\n", j, G.visited[j]);
		}

	}



	return 0;
}