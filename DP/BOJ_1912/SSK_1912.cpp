#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> origin;


int main() {
	int array_size;
	int sum_value=0;
	int max_sum_value;

	scanf("%d", &array_size);
	origin.resize(array_size);

	for (int i = 0; i < array_size; i++) {
		scanf("%d", &origin[i]);
	}
	max_sum_value = origin[0];
	for (int i = 0; i < array_size; i++) {
		if (sum_value <= 0) {
			sum_value = 0;
		}
		sum_value += origin[i];
		max_sum_value = max(max_sum_value, sum_value);
	}
	printf("%d", max_sum_value);


	return 0;
}