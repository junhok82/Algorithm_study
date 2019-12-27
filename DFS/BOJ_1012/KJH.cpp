#include <iostream>
#include <vector>
using namespace std;
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

class Graph 
{
	public :
		int C_row, C_col;
		vector<vector<bool>> C_checked;

		Graph() : C_row(0), C_col(0) {}
		Graph(int y, int x) : C_row(y), C_col(x) {
			C_checked.resize(y);

			for(int i = 0; i < y; i++)
				C_checked[i].resize(C_col,false);
		}

		void Check(const int& y, const int& x)
		{
			C_checked[y][x] = true;
		}

		void Dfs(int y, int x)
		{
			C_checked[y][x] = false;

			for(int i = 0; i < 4; i++)
			{
				const int next_y = y + dir[i][0];
				const int next_x = x + dir[i][1];

				if( (next_y >= 0 && next_y < C_row) && (next_x >= 0 && next_x < C_col))
					if(C_checked[y + dir[i][0]][x + dir[i][1]])
						Dfs(y + dir[i][0], x + dir[i][1]);
			}
		}
		
		int DfsAll()
		{
			int compo = 0;

			for(int i = 0; i < C_row; i++)
				for(int j = 0; j < C_col; j++)
					if(C_checked[i][j])
					{
						compo++;
						Dfs(i,j);
					}

			return compo;
		}
};

int main()
{
	int test_case;
	scanf("%d", &test_case);
	
	vector<int> result(test_case);
	for(int i = 0; i < test_case; i++)
	{
		int col, row, loc;
		scanf("%d %d %d", &col, &row, &loc);

		Graph G(row,col);	

		for(int j = 0; j < loc; j++)
		{
			int y, x;
			scanf("%d %d", &x, &y);
			G.Check(y,x);
		}
	
		result[i] = G.DfsAll();
	}

	for(int i = 0; i < test_case; i++)
		printf("%d\n", result[i]);

	return 0;
}
