#include <cstdio>
#include <vector>
#define MAX 1000001
using namespace std;
vector<int>arr[MAX];

int main()
{
    int n, m, k, v, i, num;
    while(scanf("%d%d", &n, &m) == 2){
        for(int i = 0; i < n; i++){
            scanf("%d", &num);
            arr[num].push_back(i+1);
        }

        while(m--){
            scanf("%d%d", &k, &v);
            if(k > arr[v].size())
                printf("0\n");
            else
                printf("%d\n", arr[v][k-1]);
        }

        for(int i = 0; i <= (MAX-1); i++)
            arr[i].clear();
    }
    return 0;
}
