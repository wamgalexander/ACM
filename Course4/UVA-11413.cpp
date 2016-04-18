#include<cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n, m, c[1000001];
    while (scanf("%d %d", &n, &m)!=EOF){
		memset(c, 0, sizeof(c));
        int l = 0, r = 0, mid;
        for (int i = 0 ; i < n ; i++) {
            scanf("%d", &c[i]);
            if (c[i] > l) l = c[i];
            r += c[i];
        }

        while (l < r){
            mid = (l + r)/2;
            int sum = 0, cnt = 0;
            for (int i = 0 ; i < n ; i++){
                sum += c[i];
                if (sum > mid) {
                    cnt++;
                    sum = c[i];
                }
                else if (sum == mid){
                    cnt++;
                    sum = 0;
                }
            }
            if (sum>0) cnt++;

            if (cnt > m) l = mid + 1;
            else r = mid;
        }
        printf("%d\n", l);
    }
    return 0;
}
