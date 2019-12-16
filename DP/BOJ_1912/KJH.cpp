#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num;
	scanf("%d", &num);

	vector<int> arr(num);
	int dp;
	int result;

	for(int i = 0; i < num; i++)
		scanf("%d", &arr[i]);

	dp = arr[0];
	result = arr[0];

	for(int i = 1; i < num; i++)
	{
		dp = max(dp + arr[i], arr[i]);
		result = max(dp, result);

		if(dp < 0)
			dp = 0;
	}

	cout << result;

	return 0;

}
