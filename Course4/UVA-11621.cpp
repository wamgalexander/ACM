#include <cstdio>
using namespace std;

int Next[330];

int bs(int key, int r)
{
	int l = 0, mid;
	while (l < r) {
		mid = (l + r)/2;
		if (Next[mid] < key)
			l = mid + 1;
		else r = mid;
	}
	return r;
}

int main()
{
	int two = 0,three = 0,cnt = 0, n;
	Next[0] = 1;
	while(Next[cnt] > Next[cnt-1]){
		if (Next[two]*2 < Next[three]*3)
			Next[++cnt] = Next[two++]*2;
		else {
			if (Next[three]*3 == Next[two]*2) two ++;
			Next[++cnt] = Next[three++]*3;
		}
	}

	while (scanf("%d", &n)==1 && n)
		printf("%d\n", Next[bs(n, cnt)]);

	return 0;
}
