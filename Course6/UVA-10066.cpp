#include<cstdio>

int main()
{
	int n1, n2, case_num = 1;
	while(scanf("%d%d", &n1, &n2) != EOF && n1 != 0 && n2 != 0)
	{
		int stone1[105] = {0}, stone2[105] = {0}, LCS[105][105] = {0};

		for(int i = 1 ; i <= n1 ; ++i)
			scanf("%d", &stone1[i]);
		for(int i = 1 ; i <= n2 ; ++i)
			scanf("%d", &stone2[i]);

		for(int i = 1 ; i <= n1 ; i++){
			for(int j = 1 ; j <= n2 ; j++){
				if(stone1[i] == stone2[j])
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
				else
					LCS[i][j] = (LCS[i - 1][j] > LCS[i][j - 1])? LCS[i - 1][j] : LCS[i][j - 1];

			}
		}

		printf("Twin Towers #%d\n", case_num++);
		printf("Number of Tiles : %d\n\n", LCS[n1][n2]);
	}

	return 0;
}
