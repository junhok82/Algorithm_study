#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
vector<int> dp;
const int max_size = 100001;

int F(int n, const int& k)
{
	if(n > 1)
		dp[n-1] = min(dp[n-1], F(n-1,k));

	cout << "dp[" << n-1 << "] = " << dp[n-1] << " k = " << k << endl;
	
	if(n >= k)
		if(dp[n-k] != max_size)
			return dp[n-k] + 1;

	return max_size;
}

int main()
{
	int num, val;
	scanf("%d %d", &num, &val);

	arr.resize(num);
	dp.resize(10001, max_size);
	dp[0] = 0;

	for(int i = 0; i < num; i++)
		scanf("%d", &arr[i]);
	for(int i = 0; i < num; i++)
		F(val + 1,arr[i]);

	if(dp[val] != max_size)
		printf("%d", dp[val]);
	else
		printf("-1");
	return 0;
}
