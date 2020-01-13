#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(char* dirs)
{	int answer=0;
	bool xLine[10][11] = { false };
	bool yLine[11][10] = { false };
	int len = strlen(dirs);
	int x=0, y=0;
	
	

	for (int i = 0; i < len; i++) {
		switch (dirs[i]) {
		case 'U':
			y++;
			if (y > 5) {
				y = 5;
				continue;
			}
			yLine[x + 5][y + 4] = true;
			break;
		case 'D':
			y--;
			if (y < -5) {
				y = -5;
				continue;
			}
			yLine[x + 5][y + 5] = true;
			break;
		case 'R':
			x++;
			if (x > 5) {
				x = 5;
				continue;
			}
			xLine[x + 4][y + 5] = true;
			break;
		case 'L':
			x--;
			if (x < -5) {
				x = -5;
				continue;
			}
			xLine[x + 5][y + 5] = true;
			break;
		}
		printf("x=%d, y=%d\n", x, y);
	}
	for (int i = 0; i<10; i++) {
		for (int j = 0; j<11; j++) {
			if (xLine[i][j]) {
				answer++;
			}
			if (yLine[j][i]) {
				answer++;
			}
		}
	}

	printf("x=%d, y=%d\n", x, y);
	return answer;
}