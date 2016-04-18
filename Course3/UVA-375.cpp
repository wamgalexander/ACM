#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    double B, H;
    const double pi = 2 * asin(1);
    int Case;
    scanf("%d", &Case);
    while (Case--){
        scanf("%lf %lf", &B, &H);
        double C = 0;
        while (1){
            double T = hypot(B/2, H);
            double R = (B*H)/(2*T+B);
            if (R < 0.000001) break;
            C += (2 * pi * R);

            double new_H = H - 2*R;
            B = B * (new_H / H);
            H = new_H;
        }
        printf("%13.6f\n", C);
        if (Case) printf("\n");
    }
    return 0;
}
