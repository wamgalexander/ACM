#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 20000

int main()
{
	int n, m, w[MAX], d[MAX], ans[MAX];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &w[i], &d[i]);

	for (int i = 0; i < n; i++)
        for (int j = m; j >= w[i]; j--)
            ans[j] = max(ans[j], ans[j - w[i]] + d[i]);

    printf("%d\n", ans[m]);
    return 0;
}
