#include <cstdio>
#define MAX 1001

float f[MAX];
int cnt[MAX], des[MAX];
void solve(int n);

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for (int i = 0 ; i < n ; ++i)
            scanf("%f", &f[i]);
        solve(n);
    }

    return 0;
}

void solve(int n){
    int ans = 0;
    for(int i = 0 ; i < n ; ++i){
        cnt[i] = 1;
        for(int j = i - 1 ; j >= 0 ; --j)
            if(f[i] > f[j] && cnt[j] + 1 > cnt[i])
                cnt[i] = cnt[j] + 1;
    }

    for(int i = n - 1; i >= 0; --i){
        des[i] = 1;
        for(int j = i + 1 ; j < n ; ++j)
            if (f[i] > f[j] && des[j] + 1 > des[i])
                des[i] = des[j] + 1;
    }

    for(int i = 0 ; i < n - 1 ; ++i)
        for(int j = i + 1 ; j < n ; ++j)
            if(cnt[i] + des[j] > ans)
                ans = cnt[i] + des[j];

    printf("%d\n", n - ans);
}
