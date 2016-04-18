#include <cstdio>
#include <algorithm>
using namespace std;

int ans[100005];

int main()
{
    int money, N, n[11], d[11];
    while (scanf("%d %d", &money, &N) != EOF) {
        for (int i = 0; i < N; ++i)
            scanf("%d %d", &n[i], &d[i]);
        fill(ans, ans+money+1, 0);

        for (int i = 0 ; i < N ; i++) {
            int l = n[i];
            while (l > 10) {
                for (int j = 1; j <= l; l -= j, j *= 2)
                    for (int k = money ; k - d[i]*j >= 0 ; k--)
                        ans[k] = max(ans[k], ans[k-d[i]*j] + d[i]*j);
            }

            for (int j = 0 ; j < l ; j++)
                for (int k = money ; k - d[i] >= 0 ; k--)
                    ans[k] = max(ans[k], ans[k-d[i]] + d[i]);
        }
        printf("%d\n", ans[money]);
    }

	return 0;
}
