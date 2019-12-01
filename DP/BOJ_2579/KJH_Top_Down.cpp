#include <iostream>
#include <vector>
using namespace std;
vector<int> dp;
vector<int> value;

int Func(int data)
{
	if(data <= 0)
		return 0;

	dp[data] = max(dp[data], value[data] + value[data-1] + Func(data-3));
	dp[data] = max(dp[data], value[data] + Func(data-2));

	return dp[data];
}

int main()
{
	int stair;
	scanf("%d", &stair);

	value.resize(stair + 1);
	dp.resize(stair + 1, 0);

	for(int i = 1; i <= stair; i++)
		scanf("%d", &value[i]);
		
	cout << Func(stair);

	return 0;
}
