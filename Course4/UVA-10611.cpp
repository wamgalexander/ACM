#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, q, t, h[50000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &h[i]);

	scanf("%d", &q);
	while (q--) {
		scanf("%d", &t);
		int low = lower_bound(h, h + n, t) - h - 1;
		int up = upper_bound(h, h + n, t) - h;
		if (low >= 0 && low < n)
			printf("%d", h[low]);
		else
			printf("X");

		printf(" ");

		if (up >= 0 && up < n)
			printf("%d", h[up]);
		else
			printf("X");

		printf("\n");
	}
	return 0;
}
