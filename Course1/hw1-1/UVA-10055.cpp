#include <cstdio>

int main(){
	long long a,b;
	while(scanf("%llu %llu", &a, &b)!=EOF){
		if(b-a < 0)
			printf("%llu\n", a-b);
		else
			printf("%llu\n", b-a);
	}
	return 0;
}
