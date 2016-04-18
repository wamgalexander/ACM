#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 50
using namespace std;

char s1[MAX], s2[MAX];
int LCS[MAX][MAX], N[MAX][MAX];

int main()
{
    int t, case_num = 0;
    scanf("%d%*c", &t);
    while (t--)
    {
        gets(s1+1);
        gets(s2+1);

        for (int i = 0 ; i < MAX ; ++i)
            LCS[0][i] = LCS[i][0] = i,
            N[0][i] = N[i][0] = 1;

        int len1 = strlen(s1+1), len2 = strlen(s2+1);

        for (int i = 1 ; i <= len1 ; ++i)
            for (int j = 1; j <= len2; ++j)
                if (s1[i] == s2[j]){
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                    N[i][j] = N[i-1][j-1];
                }
                else{
                    LCS[i][j] = min(LCS[i-1][j], LCS[i][j-1]) + 1;
                    if (LCS[i-1][j] < LCS[i][j-1])
                        N[i][j] = N[i-1][j];
                    else if (LCS[i-1][j] > LCS[i][j-1])
                        N[i][j] = N[i][j-1];
                    else
                        N[i][j] = N[i-1][j] + N[i][j-1];
                }

        printf("Case #%d: %d %d\n", ++case_num, LCS[len1][len2], N[len1][len2]);
    }
    return 0;
}
