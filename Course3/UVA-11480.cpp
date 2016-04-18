#include <cstdio>

int main() {
    int n, case_num = 0;
    while(scanf("%d", &n) == 1 && n) {
        int a, b, c;
        long long ans = 0;
        for(a = n/3 ; a >= 1; a--) {
            b = a + 1;
            c = b + 1;
            if(a + b + c <= n) {
                c--;
                ans += (n - a - b - c + 1)/2;
            }
        }
        printf("Case %d: %lld\n", ++case_num, ans);
    }
    return 0;
}
