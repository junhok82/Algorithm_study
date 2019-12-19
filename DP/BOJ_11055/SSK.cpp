#include<cstdio>
#include<algorithm>

using namespace std;
typedef struct increse_sequence {
	int min;
	int max;
	int sum;
}IS;

IS dp[1000];
int seq[1000];
int seq_len;

int main() {
	scanf("%d", &seq_len);
	for (int i = 0; i < seq_len; i++) {
		scanf("%d", &seq[i]);
	}

	dp[0].min = seq[0];
	dp[0].max = seq[0];
	dp[0].sum = seq[0];


	for (int i = 1; i < seq_len; i++) {
		dp[i].max = seq[i];
		dp[i].min = seq[i];
		dp[i].sum = seq[i];
		for (int j = i-1; j >=0; j--) {
			if (dp[j].min < seq[i] && dp[j].max < seq[i]) {
				if (dp[i].sum < dp[j].sum + seq[i]) {
					dp[i].min = dp[j].min;
					dp[i].sum = dp[j].sum + seq[i];
				}
			}
		}
	}

	int sum_max=-1;
	for (int i = 0; i < seq_len; i++) {
		if (sum_max < dp[i].sum) {
			sum_max = dp[i].sum;
		}
	}

	printf("%d", sum_max);


	/*printf("min = ");
	for (int i = 0; i < seq_len; i++) {
		printf("%4d", dp[i].min);
	}printf("\n");

	printf("max = ");
	for (int i = 0; i < seq_len; i++) {
		printf("%4d", dp[i].max);
	}printf("\n");

	printf("sum = ");
	for (int i = 0; i < seq_len; i++) {
		printf("%4d", dp[i].sum);
	}printf("\n");*/


	return 0;
}