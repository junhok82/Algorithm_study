#include<iostream>
#include<vector>
using namespace std;


class Gragh {
public:
	int n; // 학생수
	int findX;
	vector<vector<int> > student;
	vector<bool> visited; // 탈출조건 visited
	vector<bool> check; //


	Gragh(int n1): n(n1) {
		student.resize(n + 1);
		visited.resize(n + 1, false);
		check.resize(n + 1, false);
	}
	
	//단방향 간선 추가
	void addEdge(int u, int v) {
		student[u].push_back(v);
	}

	// 팀을 이루었는지 검사
	void dfs(int start) {
		if (visited[start]) return;
	
		visited[start] = true;
		cout << start << "\n";
		for (int i = 0; i < student[start].size(); i++) {
			int y = student[start][i];

			if (y == findX) 
				check[findX] = true;

			if (!visited[y]) {
				dfs(y);
			}
		}
	}
};

int main() {

	int T; // Testcase
	vector<int> result; // 결과집합
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N; // 학생 수
		cin >> N;
		
		//class init
		Gragh G(N);
		fill(G.check.begin(), G.check.end(), false);

		result.push_back(N);

		for (int i = 1; i < N+1; i++) {
			int input;
			cin >> input;
				
			G.addEdge(i, input);
		}

		for (int i = 1; i < N + 1; i++) {
			cout << "--- DFS ---\n";

			fill(G.visited.begin(), G.visited.end(), false);

			G.findX = i;
			if(!G.visited[i]) 
				G.dfs(i);
		}
	
		for (int i = 1; i < N + 1; i++) {
			if (G.check[i]) result[t]--;
		}
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << "\n";
	}

}