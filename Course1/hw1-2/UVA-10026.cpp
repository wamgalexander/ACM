#include <cstdio>
#include <algorithm>

using namespace std;

struct job{
	double time;
	double fine;
	int num;
};

bool cmp(job a, job b){
	bool fact = false;
	double cp_a = a.fine/a.time, cp_b = b.fine/b.time;
	if(cp_a > cp_b)
		fact = true;
	else if(cp_a == cp_b)
		if(a.num < b.num)
			fact = true;		
	return fact;
}

int main(){
	int case_num, N;
	job task[1000];

	while(scanf("%d", &case_num)!= EOF){
		for(int i = 0 ; i < case_num ; i++){
			if(i) printf("\n");
			scanf("%d", &N);
			for(int j = 0; j < N ; j++){
				scanf("%lf %lf", &(task[j].time), &(task[j].fine));
				task[j].num = j+1;
			}
			sort(task, task+N, cmp);

			for(int j = 0 ; j < N ; j++){
				if(j) printf(" ");
				printf("%d", task[j].num);
			}
			printf("\n");
		}
	}
	return 0;
}