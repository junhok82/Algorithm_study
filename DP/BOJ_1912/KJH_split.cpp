#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int middle_sum(vector<T> data, const int& mid_size)
{
	int left_curr = data[mid_size-1];
	int left_temp = left_curr;
	for(int i = mid_size - 2; i >= 0; i--)
	{
		left_curr += data[i];
		if(left_curr > left_temp)
			left_temp = left_curr;
	}

	int right_curr = data[mid_size];
	int right_temp = right_curr;
	for(int i = mid_size + 1; i < data.size(); i++)
	{
		right_curr += data[i];
		if(right_curr > right_temp)
			right_temp = right_curr;
	}

	return right_temp + left_temp;
}

int split_arr(vector<int> data)
{
	if(data.size() == 1)
		return data[0];

	int mid_size = data.size() / 2;

	const int left = split_arr(vector<int>(data.begin(), data.begin() + mid_size));
	const int right = split_arr(vector<int>(data.begin() + mid_size, data.end()));
	const int mid = middle_sum(data, mid_size);
	
	return max(mid, max(left, right));
}

int main()
{
	int num;
	scanf("%d", &num);

	vector<int> val(num);

	for(int i = 0; i < num; i++)
		scanf("%d", &val[i]);

	cout << split_arr(val);
	return 0;
}
