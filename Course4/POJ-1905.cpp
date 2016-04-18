#include <cstdio>
#include <cmath>
using namespace std;

double esp = 1e-5;
int main()
{
    double L, n, C;
    while (scanf("%lf %lf %lf", &L, &n, &C) != EOF)
    {
        if (L < 0 && n < 0 && C < 0)
            break;
        double l, r, R, mid, LL = (1 + n * C) * L;
        l = 0, r = L / 2;
        while (r - l > esp)
        {
            mid = (r + l) / 2;
            R = ((mid * mid * 4) + (L * L)) / (8 * mid);
            if ((2 * R * asin(L / (2 * R))) < LL)
                l = mid;
            else
                r = mid;
        }
        printf("%.3f\n", mid);
    }
    return 0;
}
