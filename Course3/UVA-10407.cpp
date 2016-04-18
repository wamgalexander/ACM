#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
long int gcd(long int x, long int y);

int main(){
	long int current, next, temp;
	while (scanf("%ld", &current) != EOF && current){
		scanf("%ld", &next);
		temp = abs(next - current);

		while (scanf("%ld", &next) == 1 && next)
			temp = gcd(temp, abs(next-current));
		printf("%ld\n", temp);
	}
	return 0;
}

long int gcd(long int x, long int y){
	// x = q*y + r
	long int r;
	while (y != 0){
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}
