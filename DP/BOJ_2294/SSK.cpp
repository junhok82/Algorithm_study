#include<cstdio>
#include<vector>
#include<algorithm>

int n, k;
using namespace std;
vector<int> coin_value;
vector<int> dp;

int main() {
	scanf("%d %d", &n, &k);
	
	coin_value.resize(n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if (i != 0) {
			bool check_value = false;
			for (int j = 0; j < i; j++) {
				if (coin_value[j] == temp || temp>k) { //중복 발생, k보다 클 때
					n--;
					i--;
					check_value = true;
					break;
				}
				else if (k == temp) { //동전에서 k값과 동일할 때
					printf("1");
					return 0;
				}
			}
			if (check_value) {
				continue;
			}
			else {
				coin_value[i] = temp;
			}
		}else coin_value[i] = temp;
	}
	dp.resize(k+1);
	for (int i = 1; i < k+1; i++) {
		dp[i] = 10001;
	}dp[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = coin_value[i]; j < k+1; j++) {
			dp[j] = min(dp[j], dp[j - coin_value[i]] + 1);
		}
	}
	
	if (dp[k] == 10001) printf("-1");
	else printf("%d", dp[k]);
	return 0;
}