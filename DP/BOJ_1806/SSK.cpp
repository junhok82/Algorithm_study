#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> value;

int main() {
	int sum_value = 0;
	int min_count = 100000;
	int S, N;

	scanf("%d %d", &N, &S);
	value.resize(N+1);
	for (int i = 0; i < N; i++) {
		scanf("%d", &value[i]);
		if (S == value[i]) {
			min_count = 1;
		}
	}

	int low = 0, high = 0;
	sum_value = value[low];
	while (low <= high && high < N)	{
		if (sum_value < S)
			sum_value += value[++high];
		else if (sum_value == S) {
			min_count = min(min_count, (high - low + 1));
			sum_value += value[++high];
			sum_value -= value[low++];
		}
		else if (sum_value > S)	{
			min_count = min(min_count, (high - low + 1));
			sum_value -= value[low++];
		}
	}
	if (min_count >= 100000) printf("0");
	else printf("%d", min_count);
	
	return 0;
}