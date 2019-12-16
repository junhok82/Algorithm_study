#include<cstdio>
#include<vector>
#include<algorithm>

#include<conio.h>


using namespace std;

int n,k;
bool check;
vector<int> coin_value;
int test[100];

bool rcomb(int index, int cnt, int cnt_max) {
	//if (sum > k) return false;
	if (cnt == cnt_max) {
		int sum = 0;
		for (int i = 0; i < cnt_max; i++) {
			sum += test[i];
			printf("%d\t", test[i]);
		}
		printf("===%d\n",sum);
		if (sum == k) {
			printf("true~~\n");
			return true;
		}
		return false;
	}
	

	for (int i = index; i < n; i++) {
		
		test[cnt] = coin_value[i];
		rcomb(i, cnt + 1, cnt_max);
	}
}

int main(void) {

	scanf("%d %d", &n, &k);

	//최소화작업
	coin_value.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &coin_value[i]);
	}

	for (int i = 1; i < n+1; i++) {
		rcomb(0, 0, i);
	}
	

	system("pause");
}
