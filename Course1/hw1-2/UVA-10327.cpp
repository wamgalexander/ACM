#include <cstdio>
#include <cstring>

int main(){
	int n, arr[1000],cnt;
	while(scanf("%d", &n) != EOF){
		cnt = 0;
		memset(arr, 0, sizeof(int)*1000);

		for(int i = 0 ; i < n ; i++)
			scanf("%d", &arr[i]);

		for(int i = 0; i < n ; i++)
			for(int j = i + 1 ; j < n ; j++)
				if(arr[i] > arr[j]) cnt++;

		printf("Minimum exchange operations : %d\n", cnt);
	}
	return 0;
}
