#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n,k,i;
	char c[5];
	scanf("%d", &n);

	int arr[n];
	for(i = 0 ; i < n ; i++)
		scanf("%d", &arr[i]);
	sort(arr,arr+n);

	scanf("%s", c);
	scanf("%d", &k);
	while(k){
		scanf("%d", &i);
		printf("%d\n", arr[i-1]);
		k--;
	}

	return 0;
}
