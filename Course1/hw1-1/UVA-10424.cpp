#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int Sum(int num){
	int n = num, sum = 0;
	while(1){
		if(n == 0){
			if(sum < 10) break;
			else{
				n = sum;
				sum = 0;
			}
		}
		sum += (n%10);
		n/=10;
	}

	return sum;
}

int get_input_sum(char *n){
	int sum = 0;
	for(int i = 0; i < strlen(n) ; i++){
		if(n[i] >= 'a' && n[i] <= 'z')
			sum += (n[i]-'a'+1);
		else if(n[i] >= 'A' && n[i] <= 'Z')
			sum += (n[i]-'A'+1);
	}
	return sum;
}

int main(){
	char name1[25], name2[25];
	int sum1, sum2, n1, n2;
	double result;
	memset(name1, 0, sizeof(name1));
	memset(name2, 0, sizeof(name2));
	while(gets(name1)){
		gets(name2);
		n1 = 0;
		n2 = 0;
		result = 0.0f;

		n1 = get_input_sum(name1);
		n2 = get_input_sum(name2);
		
		sum1 = Sum(n1);
		sum2 = Sum(n2);
		if(sum1 > sum2) swap(sum1, sum2);
		result = 100*(double)sum1/(double)sum2;
		printf("%.2f %%\n", result); 		
	}

	return 0;
}