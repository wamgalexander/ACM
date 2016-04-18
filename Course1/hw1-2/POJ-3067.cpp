#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long tree[1001];
typedef struct c
{
    int e, w;
}City;

bool cmp(City a, City b)
{
    if (a.e == b.e)
        return a.w > b.w;
    else
        return a.e > b.e;
}

void update(int i, int v)
{
    for (; i <= 1000; i += (i & -i))
        tree[i] += v;
}

long long read(int i)
{
    long long sum = 0;
    for (; i > 0; i -= (i & -i))
        sum += tree[i];
    return sum;
}

int main()
{
    int t, i, j, n, m, k;
    long long cross;
    City node[1001 * 1001];
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        cross = 0;
        memset(node, 0, sizeof(node));
        memset(tree, 0, sizeof(tree));
        scanf("%d %d %d", &n, &m, &k);
        for (j = 1; j <= k; j++)
            scanf("%d %d", &node[j].e, &node[j].w);
        sort(node+1, node+1+k, cmp);
        for (j = 1; j <= k; j++)
        {
            cross += read(node[j].w-1);
            update(node[j].w, 1);
        }
        printf("Test case %d: %lld\n", i+1, cross);
    }
    return 0;
}