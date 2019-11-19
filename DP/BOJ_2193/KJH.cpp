#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num;
	scanf("%d", &num);
	
	vector<long> dp(num+1,1);

	if(num > 2)
		for(int n = 3; n <= num; n++)
			dp[n] = dp[n-2] + dp[n-1];

	printf("%ld", dp[num]);
	return 0;
}
