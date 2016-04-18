#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int LIS(vector<int> arr);

int main(){
	int num, t = 1;
	vector<int> arr;
	while(scanf("%d", &num) != EOF){
		if(num == -1){
			if(scanf("%d", &num) != EOF){
				printf("Test #%d:\n", t++);
				printf("maximum possible interceptions: %d\n", LIS(arr));
				for(int i = 0 ; i < arr.size() ; i++)
					printf("%d ", arr[i]);
				printf("\n");

				if(num == -1)
					break;
				else{
					arr.clear();
					arr.push_back(num);
				}
			}
		}
		else
			arr.push_back(num);
	}
	return 0;
}

int LIS(vector<int> arr){
	int m = 1, len = arr.size();
	int tmp[len+1], pos[len+1];
	memset(tmp, 0, sizeof(tmp));
	memset(pos, 0, sizeof(pos));
	tmp[0] = arr[0];
	for(int i = 0 ; i < arr.size() ; i++){
		int t = lower_bound(tmp, tmp+len, arr[i]) - tmp;
		tmp[t] = arr[i];
		pos[i] = t;
		m = t+1 > m ? t+1 : m;
	}

	return m;
}
