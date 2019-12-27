#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100000
using namespace std;

vector<int> coin(101);
vector<int> dp(101, INF);
int N, K;

int main() {
	cin >> N >> K;
	dp[0] = 0;

	for (int i = 1; i <= N; i++) {
		cin >> coin[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = coin[i]; j <= K; j++) {
			dp[j + 1] = min(dp[j + 1],  dp[j - coin[i]] + 1);
			cout << dp[j] << endl;
		}
	}

	if (dp[K] == INF)
		cout << "-1";
	else
		cout << dp[K];

	cin >> N;

	return 0;
}
