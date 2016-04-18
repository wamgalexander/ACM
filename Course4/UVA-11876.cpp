#include <cstdio>
#include <cstring>
#define MAX 1000001
using namespace std;

int N, NOD[MAX+10], pre[MAX+10];
bool stat[MAX+100];

int div_cnt(int M){
	int i, cnt = 0;
	for(i = 1 ; i*i < M ; i++)
		if( M % i == 0 )
			cnt += 2;
	if(i * i == M) cnt++;
	return cnt;
}

void nod_cnt(){
	memset(stat, false, sizeof(stat));
	NOD[0] = 1, stat[1] = true;
	for (int i = 1; i < MAX; i++){
		NOD[i] = NOD[i-1] + div_cnt(NOD[i-1]);
		stat[NOD[i]] = true;
		if( NOD[i] >= MAX ){
			N = i;
			break;
		}
	}
}

int main(){
	nod_cnt();
	pre[0] = 0;
	int t;
	bool flag = true;

	for(int i = 1 ; i <= MAX ; i++){
		if(stat[i])
			pre[i] = pre[i-1] + 1;
		else
			pre[i] = pre[i-1];
	}

	scanf("%d", &t);
	for (int i = 1 ; i <= t ; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("Case %d: %d\n", i, pre[b] - pre[a-1]);
	}
	return 0;
}
