#include <cstdio>

int gcb(int a, int b){
	if(a == 0) return b;
	return gcb(b%a, a);
}

int main(){
	int a, b, c;
	while(scanf("%d %d", &a, &b) != EOF){
		c = gcb(a,b);
		printf("%10d%10d    %s\n\n", a, b, (c == 1)? "Good Choice" : "Bad Choice");
	}
	return 0;
}
