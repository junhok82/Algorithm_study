#include <string>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class Graph {
public:
	vector<vector<int>> adj;
	void addEdge(int u_x, int u_y, int v_x, int v_y) {
		adj[u_x + 5 + (u_y + 5) * 11].push_back(v_x + 5 + (v_y + 5) * 11);
		adj[v_x + 5 + (v_y + 5) * 11].push_back(u_x + 5 + (u_y + 5) * 11);
	}

	int dfs() {
		int count = 0;
		for (int i = 0; i < 121; i++) {
			sort(adj[i].begin(), adj[i].end());
			adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
			for (int j : adj[i]) {
				count++;
			}
		}
		return count / 2;
	}
};


int solution(string dirs) {
	int answer = 0;
    int len = dirs.length();
	int x = 0, y = 0;
	Graph g;
	g.adj.resize(121);

	for (int i = 0; i < len; i++) {
		switch (dirs[i]) {
		case 'U':
			y++;
			if (y > 5) {
				y = 5;
				continue;
			}
			g.addEdge(x, y - 1, x, y);
			break;
		case 'D':
			y--;
			if (y < -5) {
				y = -5;
				continue;
			}
			g.addEdge(x, y +1, x, y);
			break;
		case 'R':
			x++;
			if (x > 5) {
				x = 5;
				continue;
			}
			g.addEdge(x-1, y, x, y);
			break;
		case 'L':
			x--;
			if (x < -5) {
				x = -5;
				continue;
			}
			g.addEdge(x+1, y, x, y);
			break;
		}
		
	}

    answer = g.dfs();
	return answer;
}