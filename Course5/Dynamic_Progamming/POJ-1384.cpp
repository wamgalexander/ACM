#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 99999
int ans[10005];

int main()
{
	int t, E, F, n, p[501], w[501];
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &E, &F, &n);
		for (int i = 0 ; i < n ; i++)
			scanf("%d %d", &p[i], &w[i]);

		F = F-E;
		fill (ans, ans+10005, INF);
		ans[0] = 0;
		for (int i = 0 ; i < n ; i++)
			for (int j = 0 ; j + w[i] <= F ; j++)
				ans[j+w[i]] = min(ans[j+w[i]], ans[j] + p[i]);

		if (ans[F] == INF)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", ans[F]);
	}
}
