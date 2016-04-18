#include<cstdio>
#include<cstring>

int LCS[1005][1005] = {0};

int main()
{
    char s1[1005], s2[1005];
    while(gets(s1))
    {
        gets(s2);
        memset(LCS, 0, sizeof(LCS));
        int s1_len = strlen(s1), s2_len = strlen(s2);

        for(int i = 1 ; i <= s1_len ; ++i)
            for(int j = 1 ; j <= s2_len ; ++j)
                if(s1[i-1] == s2[j-1])
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                else
                    LCS[i][j] = (LCS[i-1][j] > LCS[i][j-1])? LCS[i-1][j] : LCS[i][j-1];

        printf( "%d\n", LCS[s1_len][s2_len] );
    }
    return 0;
}
