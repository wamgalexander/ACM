#include <cstdio>
#include <algorithm>
#define MAX 1010
#define MID_MAX 100010

using namespace std;

typedef struct point{
	long long x;
	long long y;
} Point;

typedef struct mid{
	long long x;
	long long y;
}Mid;

bool cmp(Mid a, Mid b){
	if(a.x == b.x)
		return a.y > b.y;
	return a.x > b.x;
}

int Parallelogram_Counting(int m, Mid mid[]){
	int cnt = 1 , ans= 0;
	for(int i = 0 ; i < m-1 ; i++){
		if(mid[i].x == mid[i+1].x && mid[i].y == mid[i+1].y)
			cnt++;
		else if(cnt > 1){
			ans += cnt*(cnt-1)/2;
			cnt = 1;
		}
	}
	return ans;
}

Mid mid[MAX*MAX];
Point p[MAX];

int main(){
	int m, ans, k, n;

	scanf("%d", &k);
	while(k--){
		ans = m = 0;
		scanf("%d", &n);
		for(int i = 0 ; i < n ; i++)
			scanf("%lld %lld", &p[i].x, &p[i].y);

		for(int i = 0 ; i < n ; i++){
			for(int j = i+1; j < n ; j++){
				mid[m].x = p[i].x + p[j].x;
				mid[m].y = p[i].y + p[j].y;
				m++;
			}
		}

		sort(mid, mid+m, cmp);
		ans = Parallelogram_Counting(m, mid);
		printf("%d\n", ans);
	}
	return 0;
}
