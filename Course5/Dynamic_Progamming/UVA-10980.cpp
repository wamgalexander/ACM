#include <cstdio>
#include <algorithm>
#include <iostream>
#include <sstream>
#define INIF 0xfffffff
using namespace std;

int main() {
    int n1, n2, n, w, v, q;
    char c;
    int case_num = 0;
    while(scanf("%d.%d %d", &n1, &n2 ,&n) == 3) {
        int m = n1*100 + n2;
        int ans[205] = {};

        for(int i = 1; i < 205; i++)
			ans[i] = 0xfffffff;

        for(int i = 1 ; i < 205 ; i++)
            ans[i] = min(ans[i], ans[i-1]+m);

        for(int i = 0 ; i < n ; i++) {
            scanf("%d %d.%d", &w, &n1, &n2);
            v = n1*100 + n2;
            for(int j = w ; j <= 200 ; j++)
                ans[j] = min(ans[j], ans[j-w]+v);
        }
        for(int j = 200 ; j >= 0 ; j--)
            ans[j] = min(ans[j], ans[j+1]);

        printf("Case %d:\n", ++case_num);

        while(getchar() != '\n');

        string line;
        getline(cin, line);
        stringstream str_in(line);
        while(str_in >> q)
            printf("Buy %d for $%d.%02d\n", q, ans[q]/100, ans[q]%100);
    }
    return 0;
}
