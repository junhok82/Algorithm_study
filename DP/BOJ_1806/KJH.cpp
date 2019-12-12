#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num, val, curr;
	const int max_value = 100000001;
	scanf("%d %d", &num, &val);
	
	vector<int> arr(num);
	vector<int> dp(num,max_value);

	for(int i = 0; i < num; i++)
		scanf("%d", &arr[i]);

	for(int n = 0; n < num; n++)
	{
		curr = 0;
		for(int k = n; k < num; k++)
		{
			curr += arr[k];
			if(curr >= val)
			{
				dp[n] = k - n + 1;
				break;
			}
		}
		if(n > 0)
			dp[n] = min(dp[n-1],dp[n]); 
	}

	if(dp[num-1] == max_value)
		cout << 0;
	else
		cout << dp[num-1];

	return 0;
}
