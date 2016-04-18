#include <cstdlib>
#include <cstdio>
#include <cmath>

int main(){
	int H, M;
	double ang;
	while(scanf("%d:%d", &H, &M) == 2){
		if(!H && !M) break;
		ang = 0.5*abs(11*M - 60*H);
		ang = (ang > 180) ? 360-ang : ang;
		printf("%.3f\n", ang);		
	}

	return 0;
}

