#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int case_num = 0,arr[3] = {0};
	scanf("%d", &case_num);

	for(int i = 0 ; i < case_num ; i++){
		scanf("%d %d %d",&arr[0], &arr[1], &arr[2]);
		sort(arr, arr+3);
		printf("Case %d: %d\n", i+1, arr[1]);
	}

	return 0;
}