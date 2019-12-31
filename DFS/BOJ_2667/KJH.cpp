#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

class Graph 
{
	public :
		int c_size;
		vector<int> graph_size;
		vector<vector<bool>> isExist;

		Graph() : c_size(0) {}
		Graph(const int& size) : c_size(size) {
			isExist.resize(c_size);
			for(int i = 0; i < c_size; i++)
				isExist[i].resize(c_size);
		}

		int DfsCompo()
		{
			int compo = 0;

			for(int i = 0; i < c_size; i++)
				for(int j = 0; j < c_size; j++)
					if(isExist[i][j])
					{
						compo++;
						graph_size.push_back(DfsSize(i,j));
					}
			return compo;
		}

		int DfsSize(int y, int x)
		{
			int compo_size = 1;
			isExist[y][x] = false;
			
			for(int i = 0; i < 4; i++)
			{
				const int next_y = y + dir[i][0];
				const int next_x = x + dir[i][1];

				if((next_y >= 0 && next_y < c_size) && (next_x >= 0 && next_x < c_size))
					if(isExist[next_y][next_x])
						compo_size += DfsSize(next_y,next_x);
			}
			return compo_size;
		}
};

int main()
{
	int size;
	scanf("%d", &size);

	Graph G(size);
	for(int i = 0 ; i < size; i++)
	{
		cin.ignore();
		for(int j = 0; j < size; j++)
		{
			char input = cin.get();
			G.isExist[i][j] = input == '1' ? true : false;
		}
	}

	printf("%d\n", G.DfsCompo());
	sort(G.graph_size.begin(), G.graph_size.end());

	for(int curr : G.graph_size)
		printf("%d\n", curr);

	return 0;
}
