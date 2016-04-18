#include <cstdio>
#include <cstring>
using namespace std;

int n, k;
long long tmp[102][102], mod = 1000000;
long long solve(int n, int k);

int main() {
	long long ans;
	memset(tmp, -1, sizeof(tmp));
	while(scanf("%d%d", &n, &k) == 2 && (n || k)) {
		ans = solve(n, k);
		printf("%lld\n",ans);
	}
	return 0;
}

long long solve(int n, int k) {
	if(n == 0 || k == 1) return 1;

	long long ans = 0;
	if(tmp[n][k] >= 0)
		return tmp[n][k];

	for(int i = 0 ; i <= n ; i++)
		ans = (ans + solve(n - i, k - 1)) % mod;
	tmp[n][k] = ans;

	return tmp[n][k];
}
