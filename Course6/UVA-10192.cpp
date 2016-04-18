#include<cstdio>
#include<cstring>

int main()
{
    char s1[105], s2[105];
    int case_num = 1;
    while(gets(s1) && !(s1[0] == '#' && s1[1] == '\0')){
        gets(s2);
        int LCS[105][105] = {0}, n1 = strlen(s1), n2 = strlen(s2);
        for(int i = 1 ; i <= n1 ; ++i)
            for(int j = 1 ; j <= n2 ; ++j)
                if(s1[i-1] == s2[j-1])
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                else
                    LCS[i][j] = (LCS[i-1][j] > LCS[i][j-1])? LCS[i-1][j] : LCS[i][j-1];
        printf("Case #%d: you can visit at most %d cities.\n", case_num++, LCS[n1][n2]);

    }

    return 0;
}
