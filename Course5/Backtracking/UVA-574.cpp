#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> VI;

int S, n, input_list[20];
VI ans[10000];
int ans_num;

void backtracking(int index, int sum);
bool cmp(VI a, VI b);
void Print(VI &v);

int main()
{
	while (scanf("%d %d", &S, &n) && (n > 0)) {
		for (int i = 0 ; i < n ; i++)
			scanf("%d", &input_list[i]);

		for (VI &v : ans) v.clear();
		ans_num = 0;
		backtracking(0, 0);

		printf("Sums of %d:\n", S);
		if (ans_num == 0)
			printf("NONE\n");
		else {
			sort(ans, ans+ans_num, cmp);
			Print(ans[0]);
			for (int i = 1 ; i < ans_num ; i++)
				if (ans[i] != ans[i-1]) // check ans repeated
					Print(ans[i]);
		}
	}

	return 0;
}

void backtracking(int index, int sum)
{
	if (sum == S) {
		ans[ans_num + 1] = ans[ans_num];
		++ans_num;
		return;
	}

	for (int i = index ; i < n ; i++) {
		if (sum + input_list[i] <= S) {
			sum += input_list[i];
			ans[ans_num].push_back(input_list[i]);
			backtracking(i + 1, sum);
			sum -= input_list[i];
			ans[ans_num].pop_back();
		}
	}
}

bool cmp(VI a, VI b)
{
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b[i]) continue;
		return a[i] > b[i];
	}
	return a.size() > b.size();
}

void Print(VI &v)
{
	printf("%d", v[0]);
	for (int i = 1 ; i < v.size() ; i++)
		printf("+%d", v[i]);
	printf("\n");
}
