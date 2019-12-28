#include<cstdio>

int T, M, N, K;
bool **parm;

void checkParm(int a,int b) {
	parm[a][b] = false;
	if (a >= 1 && parm[a-1][b]) checkParm(a - 1,b);
	if (b >= 1 && parm[a][b-1]) checkParm(a, b - 1);
	if (a+1<M && parm[a + 1][b]) checkParm(a + 1, b);
	if (b+1<N && parm[a][b+1]) checkParm(a, b+1);

}

int main() {
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &M, &N, &K);
		parm = new bool*[M];
		for (int j = 0; j < M; j++) {
			parm[j] = new bool[N];
			for (int z = 0; z < N; z++) {
				parm[j][z] = false;
			}
		}

		for (int j = 0; j < K; j++) {
			int a, b;
			scanf("%d %d", &a, &b);
			parm[a][b] = true;
		}
		int result = 0;
		for (int j = 0; j < M; j++) {
			for (int z = 0; z < N; z++) {
				
				if (parm[j][z]) {
					result++;
					checkParm(j, z);
				}
				
			}
		}
		printf("%d\n", result);

	}


	return 0;
}