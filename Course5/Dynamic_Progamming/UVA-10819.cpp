#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> VI;

int main()
{
    int m, n;
    while (scanf("%d %d", &m , &n) != EOF)
    {
        VI p(n), f(n);
        for (int i = 0 ; i < n ; i++)
			scanf("%d %d", &p[i], &f[i]);

        int upper = m, Max = 0;
        if (upper > 1800)
            upper += 200;

        VI ans(upper + 1, 0);
        for (int i = 0 ; i < n ; i++)
            for (int j = upper ; j >= p[i] ; j--)
                if (ans[j - p[i]] > 0 || j == p[i])
                    ans[j] = max(ans[j], ans[j - p[i]] + f[i]);

        if (m >= 1801 && m <= 2000)
        {
            Max = *max_element(ans.begin(), ans.begin()+m);
            for (int j = 2001 ; j <= upper ; j++)
                Max = max(Max, ans[j]);
        }
        else
            Max = *max_element(ans.begin(), ans.end());

        printf("%d\n", Max);
    }
    return 0;
}
