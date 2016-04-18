#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> VI;

int n, track[21], track_num, Max;
VI ans, tmp;

void backtracking(int index, int sum);

int main()
{
	while (scanf("%d %d", &n, &track_num) != EOF) {
		for (int i = 0 ; i < track_num ; i++)
			scanf("%d", &track[i]);

		ans.clear();
		tmp.clear();
		Max = 0;
		backtracking(0, 0);

		int sum = 0;
		for (int i = 0 ; i < ans.size() ; i++) {
			printf("%d ", ans[i]);
			sum += ans[i];
		}
		printf("sum:%d\n", sum);
	}

	return 0;
}

void backtracking(int index, int sum)
{
	if (sum > Max) {
		ans = tmp;
		Max = sum;
	}

	for (int i = index ; i < track_num ; i++) {
		if (track[i] + sum <= n) {
			sum += track[i];
			tmp.push_back(track[i]);

			backtracking(i + 1, sum);

			sum -= track[i];
			tmp.pop_back();
		}
	}
}
