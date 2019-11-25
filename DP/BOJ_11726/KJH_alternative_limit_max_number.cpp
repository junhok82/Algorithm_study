#include <iostream>
using namespace std;

int Fec(int data)
{
	if(data == 1)
		return 1;
	return data * Fec(data-1);
}

int main()
{
	int num;
	scanf("%d", &num);

	int result = 0;					// sum of a cycle

	if(num == 1)
	{
		cout << 1;
		return 0;
	}
	
	for(int i = 0; i <= num; i++)
	{
		const int curr_1b2 = num - i;
		const int curr_2b1 = i / 2;

		if(curr_1b2 + (curr_2b1 * 2) == num)
		{
			if(curr_1b2 != 0 && curr_2b1 != 0)
				result += (((Fec(curr_1b2 + curr_2b1)) / Fec(curr_1b2)) / Fec(curr_2b1)) % 10007;
			else
				result += 1;
		}
	}

	cout << result;

	return 0;
}
