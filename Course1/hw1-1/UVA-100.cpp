#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n,i,j,a,b,len,max;

	while(scanf("%d %d", &i, &j)!= EOF){
		a = i;
		b = j;
		max = 0;
		if(i > j) swap(i,j);

		for(int m = i ; m <= j ; m++){
			len = 1;
			n = m;
			while(n != 1){
				if(n%2) n = 3*n+1;
				else n /= 2;
				len++;
			}
			if(len > max) max = len;
		}
		printf("%d %d %d\n", a, b, max);
	}

	return 0;
}
