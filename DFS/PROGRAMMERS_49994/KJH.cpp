#include <iostream>
#include <vector>
#include <string>
using namespace std;
const unsigned char UP = 0x1;
const unsigned char DOWN = 0x2;
const unsigned char RIGHT = 0x4;
const unsigned char LEFT = 0x8;

int solution(string dirs)
{
	vector<vector<unsigned char>> visited(11, vector<unsigned char>(11, 0));
	int y = 5;
	int x = 5;
	int answer = 0;

	for(int i = 0; i < dirs.size(); i++)
	{
		switch(dirs[i])
		{
			case 'U' :
				if(!(visited[y][x] & UP) && y < 10)
				{
					answer++;
					visited[y][x] |= UP;
					visited[y+1][x] |= DOWN;
				}
				if(y < 10)
					y++;
				break;
			case 'D' :
				if(!(visited[y][x] & DOWN) && y > 0)
				{
					answer++;
					visited[y][x] |= DOWN;
					visited[y-1][x] |= UP;
				}
				if(y > 0)
					y--;
				break;
			case 'R' :
				if(!(visited[y][x] & RIGHT) && x < 10)
				{
					answer++;
					visited[y][x] |= RIGHT;
					visited[y][x+1] |= LEFT;
				}
				if(x < 10)
					x++;
				break;
			case 'L' :
				if(!(visited[y][x] & LEFT) && x > 0)
				{
					answer++;
					visited[y][x] |= LEFT;
					visited[y][x-1] |= RIGHT;
				}
				if(x > 0)
					x--;
				break;
		}
	}

	return answer;
}

int main()
{
	string input;

	cin >> input;
	cout << solution(input) << endl;

	return 0;
}
