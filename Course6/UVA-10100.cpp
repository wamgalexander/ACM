#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#define MAX 1010

using namespace std;
int is_legal_input(char *s, string str[]);

int main()
{
	int cnt = 1;
	char s1[MAX], s2[MAX];
	while(gets(s1)){
		gets(s2);
		if(s1[0] == '\0' || s2[0] == '\0'){
			printf("%2d. Blank!\n", cnt++);
			continue;
		}

		string str1[MAX], str2[MAX];
		int cnt1 = is_legal_input(s1, str1);
		int cnt2 = is_legal_input(s2, str2);
		int dp[MAX][MAX] = {0};

		for(int i = 1 ; i <= cnt1 ; ++i){
			for(int j = 1 ; j <= cnt2 ; ++j){
				if(str1[i] == str2[j])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}

		printf("%2d. Length of longest match: %d\n", cnt++, dp[cnt1][cnt2]);
	}
	return 0;
}

int is_legal_input(char *s, string str[]){
	int invalid = 0, cnt = 0;
	for(int i = 0 ; i < strlen(s) ; ++i){
		char c = s[i];
		if(isalpha(c) || isdigit(c)){
			if(!invalid){
				cnt++;
				str[cnt] += c;
				invalid = 1;
			}
			else str[cnt] += c;
		}
		else invalid = 0;
	}

	return cnt;
}
