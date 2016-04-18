#include<algorithm>
#include<cstdio>

#define MAX 3000
using namespace std;

int T, N;
int s1[MAX], s2[MAX], LIS[MAX], LDS[MAX], max_i, max_d, tmp_i, tmp_d;

int main() {
	scanf("%d", &T);
	for(int t = 1 ; t <= T ; ++t){
		scanf("%d", &N);
		for(int i = 0 ; i < N; ++i)
			scanf("%d", &s1[i]);
		for(int i = 0 ; i < N ; ++i)
			scanf("%d", &s2[i]);

		max_i = max_d = 0;
		for(int i = 0 ; i < N ; ++i){
			tmp_i = tmp_d = LIS[i] = LDS[i] = s2[i];

			for(int j = 0 ; j < i ; ++j){
				if(s1[j] < s1[i])
					LIS[i] = max(LIS[i], tmp_i + LIS[j]);
				if(s1[j] > s1[i])
					LDS[i] = max(LDS[i], tmp_d + LDS[j]);
			}

			max_i = max(max_i, LIS[i]);
			max_d = max(max_d, LDS[i]);
		}

		if(max_i >= max_d)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", t, max_i, max_d);
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", t, max_d, max_i);
	}

	return 0;
}
