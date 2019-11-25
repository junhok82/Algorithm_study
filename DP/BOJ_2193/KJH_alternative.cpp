#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num;
	scanf("%d", &num);
	
	vector<vector<long>> dp(num+1, (vector<long>(2,1)));
	
	for(int i = 4; i <= num; i++)
	{
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}
	if(num < 3)
		printf("%d", 1);
	else if(num == 3)
		printf("%d", 2);
	else
		printf("%ld", dp[num][0] + dp[num][1]);
	return 0;
}
