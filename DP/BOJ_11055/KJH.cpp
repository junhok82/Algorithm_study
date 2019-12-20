#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int len, result;
	scanf("%d", &len);

	vector<int> arr(len);
	for(int i = 0; i < len; i++)
		scanf("%d", &arr[i]);

	vector<int> dp(len,0);
	dp[0] = arr[0];
	result = arr[0];

	for(int i = 1; i < len; i++)
	{
		dp[i] = arr[i];

		for(int j = 1; j <= i; j++)
			if(arr[i] > arr[i - j])
				dp[i] = max(dp[i], dp[i - j] + arr[i]);

		result = max(dp[i], result);
	}

	printf("%d", result);
	return 0;
}
