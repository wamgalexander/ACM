#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int, int> II;
typedef vector<II> VII;
VII stop;

bool cmp(II a, II b)
{
	return a.first > b.first;
}

int main()
{
	int N, L, P, n1, n2;
	stop.clear();
	while (scanf("%d", &N) != EOF) {
		priority_queue<int> pq;
		for (int i = 0; i < N ; i++){
			scanf("%d %d", &n1, &n2);
			stop.push_back(II(n1, n2));
		}
		sort(stop.begin(), stop.end() , cmp);
		stop.push_back(II(0,0));

		scanf("%d %d", &L, &P);

		int path = L - stop[0].first, sum_path = path;
		int i = 0, ans = 0, flag = 1;
		P -= path;
		while (sum_path < L && flag) {
			while (P >= 0) {
				path = stop[i].first - stop[i+1].first;
				P -= path;
				sum_path += path;
				pq.push(stop[i].second);
				++i;
				if (i == N) break;
			}

			while (P < 0 && flag) {
				if (pq.empty()) flag = 0;
				else{
					P += pq.top();
					pq.pop();
					++ans;
				}
			}
		}
		if (flag) printf("%d\n", ans);
		else puts("-1");
	}
}
