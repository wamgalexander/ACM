#include <cstdio>
#include <algorithm>
using namespace std;

int n, ans[10000] = {0}, cent[5] = {1, 5, 10, 25, 50};

int main()
{
	ans[0] = 1;
    for (int i = 0 ; i < 5 ; i++)
        for (int j = 0 ; j + cent[i] <= 7490 ; j++)
         ans[j+cent[i]] += ans[j];

    while (scanf("%d", &n) != EOF)
        printf("%d\n", ans[n]);
	return 0;
}
