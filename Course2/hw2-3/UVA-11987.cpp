#include <cstdio>
#include <vector>
#define MAX 100010
using namespace std;

int R[MAX];
vector<int> num_set[MAX];
vector<int>::iterator i;

void init(int n){
	for(int i = 0 ; i <= n ; i++){
		R[i] = i;
		num_set[i].clear();
		num_set[i].push_back(i);
	}
}

void replace_set(int x, int y){
	for(i = num_set[y].begin() ; i != num_set[y].end() ; i++){
		num_set[x].push_back(*i);
		R[*i] = x;
	}
	num_set[y].clear();
}

void Union(int x, int y){
	x = R[x], y = R[y];
	if(x == y) return;
	if(num_set[x].size() >= num_set[y].size())
		replace_set(x,y);
	else
		replace_set(y,x);
}

int main(){
	int n, m, cmd, x, y;
	while(scanf("%d %d", &n, &m) != EOF){
		init(n);
		while(m--){
			scanf("%d", &cmd);
			if(cmd == 1){
				scanf("%d %d", &x, &y);
				Union(x, y);
			}
			else if(cmd == 2){
				scanf("%d %d", &x, &y);
				if(R[x] == R[y]) continue;
				for(i = num_set[R[x]].begin() ; *i != x ; i++);
				num_set[R[x]].erase(i);
				num_set[R[y]].push_back(x);
				R[x] = R[y];
			}
			else if(cmd == 3) {
				int sum = 0;
				scanf("%d", &x);
				for(i = num_set[R[x]].begin() ; i != num_set[R[x]].end() ; i++)
					sum += *i;
				printf("%lu %d\n", num_set[R[x]].size(), sum);
			}
		}
	}

	return 0;
}
