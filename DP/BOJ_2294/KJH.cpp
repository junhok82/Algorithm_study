#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	const int max_size = 100001;
	scanf("%d %d", &n, &k);

	vector<int> val(n);
	vector<int> dp(10001, max_size);

	for(int i = 0; i < n; i++)
		scanf("%d", &val[i]);

	dp[0] = 0;
	for(int i = 0; i < n; i++)
		for(int j = val[i]; j <= k; j++)
			dp[j] = min(dp[j], dp[j - val[i]] + 1);

	if(dp[k] == max_size)
		printf("%d", -1);
	else
		printf("%d", dp[k]);

	return 0;
}
