#include <cstdio>
#include <vector>
#define MAX 101
using namespace std;
typedef vector<int> VI;

int n, elder_num[MAX], visit[MAX];
VI ans, child[MAX];
void DFS(int n);

int main()
{
    while (scanf("%d", &n) != EOF) {
		ans.clear();
		for (int i = 1 ; i <= n ; i++) {
			child[i].clear();
			elder_num[i] = 0;
			visit[i] = 0;
		}

        for (int i = 1 ; i <= n ; i++) {
            int m;
            while (scanf("%d", &m) && m != 0) {
                child[i].push_back(m);
                ++elder_num[m];
            }
        }

        for (int i = 1 ; i <= n ; i++)
            if (elder_num[i] == 0)
                DFS(i);

        for (int i = ans.size() - 1 ; i > 0 ; i--)
            printf("%d ", ans[i]);
        printf("%d\n", ans[0]);
    }
}

void DFS(int n)
{
    if (visit[n] == 1) return;
    visit[n] = 1;

    for (int i = 0 ; i < child[n].size() ; i++)
        if (visit[child[n][i]] != 2)
            DFS(child[n][i]);
    visit[n] = 2;
    ans.push_back(n);
}
