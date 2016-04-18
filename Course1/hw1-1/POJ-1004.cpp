#include <cstdio>

int main(){
	double item,sum = 0.0;
	for(int i = 0; i < 12 ; i++){
		scanf("%lf", &item);
		sum += item;
	}
	printf("$%.2f\n", sum/12);
	return 0;
}