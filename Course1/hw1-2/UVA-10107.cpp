#include <cstdio>
#include <algorithm>
#define max 10000

using namespace std;

int main(){
	long long arr[max],mid,i=0,m;
	while(scanf("%lld", &arr[i])==1){
		sort(arr, arr+i+1);
		m = i >> 1;
		if(i%2) mid = (arr[m] + arr[m+1]) >> 1;
		else mid = arr[m];
		printf("%lld\n", mid);
		i++;
	}
	return 0;
}