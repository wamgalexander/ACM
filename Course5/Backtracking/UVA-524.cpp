#include <cstdio>
using namespace std;

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
int n, case_num = 0, ans[20];

bool isPrime(int num);
void backtracking(int len, bool used[]);

int main()
{
	while (scanf("%d", &n) != EOF) {
		if (case_num++) printf("\n");
		printf("Case %d:\n", case_num);
		bool used[20] = {0};
		ans[0] = 1;
		backtracking(1, used);
	}

	return 0;
}

bool isPrime(int num)
{
	for (int i = 0 ; i < 13 ; i++)
		if (prime[i] == num)
			return true;
	return false;
}

void backtracking(int len, bool used[])
{
	if (len == n) {
		if (!isPrime(ans[n-1] + 1)) return;

		printf("1");
		for (int i = 1; i < n; i++)
			printf(" %d", ans[i]);
		printf("\n");

		return;
	}

	for (int i = 2; i <= n; i++) {
		if (used[i]) continue;
		if (isPrime(i + ans[len - 1])) {
			used[i] = 1;
			ans[len] = i;
			backtracking(len + 1, used);
			used[i] = 0;
		}
	}
}
