#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
	int n,k;
	int result = 0;
	scanf("%d %d", &n, &k);

	vector<pair<int,int>> adj;
	vector<int> dp(100001, -1);
	vector<int> tmp(100001, -1);

	dp[0] = 0;
	tmp[0] = 0;

	for(int i = 0; i < n; i++)
	{
		int input1, input2;
		scanf("%d %d", &input1, &input2);
		adj.push_back(make_pair(input1,input2));
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = adj[i].first; j <= k; j++)
		{
			if(dp[j - adj[i].first] == -1)
				continue;
			else
				dp[j] = max(dp[j], tmp[j - adj[i].first] + adj[i].second);

			result = max(dp[j], result);
		}
		tmp.assign(dp.begin(), dp.end());
	}

	printf("%d", result);

	return 0;
}
