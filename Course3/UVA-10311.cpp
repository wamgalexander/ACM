#include <cstdio>
#include <cstring>
#define MAX 100000001
#define P_MAX 10000001
using namespace std;

char visit[MAX];
int  prime[P_MAX];

int binary_search(int r, int key)
{
	int mid, l = 0;
	while (l < r) {
		mid = (l + r + 1)/2;
		if (prime[mid] >= key)
			r = mid - 1;
		else l = mid;
	}
    return l;
}

int main()
{
 	memset(visit, 0, sizeof(visit));
    int n, cnt = 0;
    for (int i = 2 ; i < MAX ; i++) {
        if (!visit[i])
            prime[cnt++] = i;
        for (int j = 0 ; j < cnt && i*prime[j] < MAX ; j++) {
            visit[i*prime[j]] = 1;
            if (i%prime[j] == 0) break;
        }
    }
	prime[cnt] = MAX;

    while (scanf("%d", &n)!=EOF) {
		if (n < 5)
			printf("%d is not the sum of two primes!\n",n);
		else if (n % 2) {
			if (prime[binary_search(cnt, n-2)+1] == n-2)
				printf("%d is the sum of %d and %d.\n", n, 2, n-2);
			else printf("%d is not the sum of two primes!\n", n);
		}else {
			int flag = 1;
			for (int i = binary_search(cnt, n/2) ; i >= 0 ; i--)
				if (prime[binary_search(cnt, n-prime[i]) + 1] == n-prime[i]) {
					printf("%d is the sum of %d and %d.\n", n, prime[i], n-prime[i]);
					flag = 0;
					break;
				}
			if (flag)
				printf("%d is not the sum of two primes!\n", n);
		}
	}

    return 0;
}
