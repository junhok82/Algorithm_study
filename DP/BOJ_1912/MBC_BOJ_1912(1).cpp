#include <iostream>
#include <vector>
using namespace std;


// variable init
vector<long long int> dp;
vector<long long int> v;
int N;
long long int mx = -1000;

int main() {
	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	// duplicate Input vector
	dp = v;
	
	if (dp[0] > mx)
		mx = dp[0];

	for (int i = 1; i < N; i++) {

		if (dp[i - 1] > 0 && dp[i] + dp[i - 1] > 0) {
			dp[i] += dp[i - 1];
		}
		//cout << "dp[" << i << "] : " << dp[i] << endl;

		if (mx < dp[i])
			mx = dp[i];
	}

	cout << mx;

	return 0;
}