#include<stdio.h>

int stair[301];
int stairNum;
long max = 0;


int Max(int n) {
	if (max < n) {
		max = n;
	}
	return max;
}

void Upstair(int count,int bindNum, int sum) {
	sum += stair[count];
	if (count == stairNum) {
		Max(sum);
		return sum;
	}
	else if(count>stairNum) {
		return ;
	}
	else {
		if (bindNum == 2) {
			Upstair(count + 2, 1, sum);
		}
		else {
			Upstair(count + 1, bindNum+1, sum);
			Upstair(count + 2, 1, sum);
		}
		
	}
}

int main() {
	scanf("%d", &stairNum);
	for (int i = 1; i < stairNum + 1; i++) {
		scanf("%d", &stair[i]);
	}
	
	Upstair(0,0,0);
	printf("%d", max);

	getch();
	return 0;
}