#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int stair;
	scanf("%d", &stair);

	vector<int> value(stair + 1, 0);
	vector<int> dp(stair + 1, 0);

	for(int i = 1; i <= stair; i++)
		scanf("%d", &value[i]);

	dp[1] = value[1];
	dp[2] = value[1] + value[2];
	dp[3] = max(value[1] + value[3], value[2] + value[3]);
	for(int i = 4; i <= stair; i++)
	{
		dp[i] = max(dp[i], value[i] + value[i-1] + dp[i-3]);
		dp[i] = max(dp[i], value[i] + dp[i-2]);
	}	
	cout << dp[stair];

	return 0;
}
