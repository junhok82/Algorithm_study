#include <iostream>
#include <vector>
using namespace std;
vector<int> dp;

int f(int data)
{
	if(dp[data] != 1000001)
		return dp[data];

	if(data % 3 == 0)
		dp[data] = min(dp[data], f(data/3) + 1);
	if(data % 2 == 0)
		dp[data] = min(dp[data], f(data/2) + 1);
	
	dp[data] = min(dp[data], f(data-1) + 1);

	return dp[data];
}

int main()
{
	int num;
	scanf("%d", &num);

	dp.resize(num+1, 1000001);
	dp[1] = 0;

	printf("%d", f(num));
	return 0;
}
