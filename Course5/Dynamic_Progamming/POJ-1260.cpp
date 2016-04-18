#include <cstdio>
#include <algorithm>
#define MAX 1001
using namespace std;

int main(){
	int t, n, ans[MAX];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int p[MAX], sum[MAX];
		for(int i = 0 ; i < n ; i++){
			scanf("%d %d", &sum[i], &p[i]);
			if(i > 0)
				sum[i] += sum[i-1];
		}

		for(int i = 0 ; i < n ; i++){
			ans[i] = (sum[i] + 10) * p[i];
			for(int j = 0 ; j < i; j++)
				ans[i] = min(ans[i], ((sum[i] - sum[j]) + 10) * p[i] + ans[j]);
		}

		printf("%d\n", ans[n-1]);
	}
	return 0;
}
