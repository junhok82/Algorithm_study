#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	const int max_size = 100000001;
	scanf("%d %d", &n, &k);

	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	int p_start = 0;
	int p_end = 0;
	int curr_value = arr[0];
	int min_len = max_size;

	while(1)
	{
		if(curr_value >= k)
		{
			min_len = min(min_len,p_end - p_start + 1);
			curr_value -= arr[p_start++];
		}
		else
			curr_value += arr[++p_end];

		if(p_end == n - 1 && curr_value < k)
			break;
	}

	if(min_len != max_size)
		printf("%d", min_len);
	else
		printf("0");
	
	return 0;
}
