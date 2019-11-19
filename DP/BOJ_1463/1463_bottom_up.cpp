#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num;
	scanf("%d", &num);

	vector<int> dp(num+1, 1000001);
	dp[1] = 0;

	for(int i = 1; i <= num; i++)
	{
		if(i % 3 == 0)
			dp[i] = min(dp[i], dp[i/3] + 1);
		if(i % 2 == 0)
			dp[i] = min(dp[i], dp[i/2] + 1);
		
		dp[i] = min(dp[i], dp[i-1] + 1);
	}

	printf("%d", dp[num]);
	return 0;
}
