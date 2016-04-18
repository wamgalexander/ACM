#include <cstdio>
#include <vector>
#define MAX 101
using namespace std;
typedef vector<int> VI;

void DFS(int n, int visit[], VI edges[], VI &ans);
int main()
{
    int N, M, a, b;
    while (scanf("%d %d", &N, &M) && (N || M)) {
        VI ans, edges[MAX];
        bool connect[MAX] = {0};
        int visit[MAX] = {0};

        while (M--) {
            scanf("%d %d", &a, &b);
            edges[a].push_back(b);
            connect[b] = 1;
        }

        for (int i = 1 ; i <= N ; i++) {
            if (!connect[i])
                DFS(i , visit, edges, ans);
        }

        for (auto i = ans.rbegin() ; i != ans.rend() ; i++)
            printf("%d ", *i);
        printf("\n");
    }
}

void DFS(int n, int visit[], VI edges[], VI &ans)
{
    if (visit[n] == 1) return;
    visit[n] = 1;

    for (int next : edges[n]) {
        if (visit[next] != 2)
            DFS(next, visit, edges, ans);
    }

    visit[n] = 2;
    ans.push_back(n);
}
