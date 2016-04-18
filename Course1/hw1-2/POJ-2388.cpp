#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n; 
	long long arr[10000];

	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++)
		scanf("%lld", &arr[i]);

	sort(arr, arr+n);
	printf("%lld", arr[n/2]);
	return 0;
}