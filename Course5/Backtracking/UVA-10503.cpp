#include <cstdio>
using namespace std;

int N, M;
int i1, i2, d1, d2, p[20], q[20];
int choosed[20];
bool backtracking(int len, int num);

int main()
{
    while (scanf("%d %d", &N, &M) && N) {
        scanf("%d %d %d %d", &i1, &i2, &d1, &d2);
        for (int i = 0 ; i < M ; i++) {
            scanf("%d %d", &p[i], &q[i]);
            choosed[i] = 0;
        }

        if (backtracking(0, i2))
			printf("YES\n");
        else
			printf("NO\n");
    }

    return 0;
}

bool backtracking(int len, int num)
{
    if (len == N) {
        if (num == d1) return true;
        return false;
    }

    for (int i = 0 ; i < M ; i++) {
        if (choosed[i]) continue;
        if (p[i] == num || q[i] == num) {
            choosed[i] = 1;

            bool checked;
            if (p[i] == num)
				checked = backtracking(len + 1, q[i]);
            else
				checked = backtracking(len + 1, p[i]);

            if (checked)
				return true;

            choosed[i] = 0;
        }
    }
    return false;
}
