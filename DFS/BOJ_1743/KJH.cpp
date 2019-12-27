#include <iostream>
#include <vector>
using namespace std;
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

class Graph 
{
	public :
		int c_row;
		int c_col;
		vector<vector<bool>> isExist;

		Graph() : c_row(0), c_col(0) {}
		Graph(const int& y, const int& x) : c_row(y), c_col(x) {
			isExist.resize(c_row);
			for(int i = 0; i < c_row; i++)
				isExist[i].resize(c_col,false);
		}

		int DfsCompo()
		{
			int size = 1;

			for(int i = 0; i < c_row; i++)
				for(int j = 0; j < c_col; j++)
					if(isExist[i][j])
						size = max(size, DfsSize(i,j));

			return size;
		}

		int DfsSize(int y, int x)
		{
			int size = 1;
			isExist[y][x] = false;

			for(int i = 0; i < 4; i++)
			{
				const int next_y = y + dir[i][0];
				const int next_x = x + dir[i][1];

				if((next_y >= 0 && next_y < c_row) && (next_x >= 0 && next_x < c_col))
					if(isExist[next_y][next_x])
						size += DfsSize(next_y,next_x);
			}
			return size;
		}
};

int main()
{
	int row, col, num;
	scanf("%d %d %d", &row, &col, &num);

	Graph G(row,col);
	for(int i = 0; i < num; i++)
	{
		int y, x;
		scanf("%d %d", &y, &x);
		G.isExist[y-1][x-1] = true;
	}

	printf("%d", G.DfsCompo());

	return 0;
}

