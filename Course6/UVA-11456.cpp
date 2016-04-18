#include <cstdio>
#include <algorithm>

#define MAX 2010
using namespace std;

int LIS[MAX], LDS[MAX], train[MAX];

int main() {
	int m, n;
	scanf("%d", &m);
	for(int i = 0 ; i < m ; ++i){
		scanf("%d", &n);
		for(int j = n-1 ; j >= 0 ; --j)
			scanf("%d", &train[j]);

		for(int j = 0 ; j < n ; ++j)
			LIS[j] = LDS[j] = 1;

		for(int j = 0 ; j < n ; ++j){
			for(int k = j + 1 ; k < n ; ++k){
				if (train[j] > train[k])
					LIS[k] = max(LIS[k], LIS[j] + 1);
				if (train[j] < train[k])
					LDS[k] = max(LDS[k], LDS[j] + 1);
			}
		}

		int max = 0;
		for(int j = 0 ; j < n ; ++j)
			if (LIS[j]+LDS[j]-1 > max)
				max = LIS[j] + LDS[j] - 1;
		printf("%d\n", max);
	}
}
