#include <cstdio>

int main(){
	int case_num = 0,org_t,add;
	double new_t;
	scanf("%d", &case_num);

	for(int i = 0 ; i < case_num ; i++){
		scanf("%d %d", &org_t, &add);
		new_t = (double)org_t + 5*(double)add/9;
		printf("Case %d: %.2f\n", i+1, new_t);
	}

	return 0;
}