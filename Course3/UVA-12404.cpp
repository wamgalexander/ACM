#include <cstdio>
#include <cmath>
using namespace std;

struct Vector{
    double x,y;
    Vector(int x_pos, int y_pos) : x(x_pos), y(y_pos){}
    Vector(double x_pos, double y_pos) : x(x_pos), y(y_pos){}

    Vector operator + (Vector P){
        return Vector(x + P.x,y + P.y);
    }

    Vector operator * (double k){
        return Vector(k * x,k * y);
    }

    Vector operator / (double k){
        return Vector(x / k,y / k);
    }

    Vector reverse(){
        return Vector(-y,x);
    }

    double abs(){
        return sqrt(x * x + y * y);
    }
};

int main(){
    int T, x1, y1, x2, y2, b, c, d;

    scanf("%d", &T);

    for(int tc = 1 ; tc <= T ; tc++){
        scanf("%d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &b, &c, &d);

        Vector A = Vector(x1,y1), AB = Vector(x2 - x1,y2 - y1);

        double a = AB.abs(), k1 = (a - c + (d * d - b * b) / (a - c)) / 2, h = sqrt(d * d - k1 * k1);
        AB = AB / AB.abs();
        Vector C_cast = A + AB * (k1 + c), D_cast = A + AB * k1;

        AB = AB.reverse();
        Vector C = C_cast + AB * h, D = D_cast + AB * h;

        printf("Case %d:\n%.8f %.8f %.8f %.8f\n", tc, C.x, C.y, D.x, D.y);
    }

    return 0;
}
