#include <cstdio>
#include <vector>
using namespace std;

vector<int> edges[6] = {{}, {2,3,5}, {1,3,5}, {1,2,4,5}, {3,5}, {1,2,3,4}};
int ans[9], used[6][6] = {0};

void find_path(int node, int len);

int main()
{
    ans[0] = 1;
    find_path(1,1);
	return 0;
}

void find_path(int node, int len)
{
    if (len == 9) {
        for (int i = 0; i < 9 ; i++)
            printf("%d", ans[i]);
        printf("\n");
    }

    for (int next : edges[node]){
        if (!used[node][next] && !used[next][node]) {
            used[node][next] = used[next][node] = 1;
            ans[len] = next;

            find_path(next, len + 1);
            used[node][next] = used[next][node] = 0; // reset edges
        }
    }
}
