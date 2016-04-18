#include <cstdio>

int main() {
	int t, n, i, j;
	long long ans[10001] = {};

	scanf("%d", &t);
	ans[0] = 0;
	for(i = 1 ; i <= 10000 ; i++)
		ans[i] = 10000;

	for(i = 1; i <= 100 ; i++) {
		for(j = i*i ; j <= 10000 ; j++)
			ans[j] = (ans[j] < ans[j-i*i] + 1) ? ans[j] : ans[j-i*i] + 1;
	}

	while(t--) {
		scanf("%d", &n);
		printf("%lld\n", ans[n]);
	}
    return 0;
}
