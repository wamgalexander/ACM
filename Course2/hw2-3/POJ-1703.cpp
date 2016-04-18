#include <cstdio>
#define MAX 200010
int p[MAX];
int rank[MAX];

void init(int n){
	for(int i = 0 ; i < n ; i++){
		p[i] = i;
		rank[i] = 0;
	}
}

int find(int x){
	return (p[x] == x) ? x : (p[x] = find(p[x]));
}

void Union(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return;
	if(rank[y] > rank[x])
		p[x] = y;
	else{
		p[y] = x;
		if(rank[x] == rank[y])
			++rank[x];
	}
}

bool same(int x, int y){
	return find(x) == find(y);
}

int main(){
	char act;
	int t, n, m, x, y;
	scanf("%d%*c", &t);
	while(t--){
		scanf("%d %d%*c", &n, &m);
		init(n*2);
		while(m--){
			scanf("%c %d %d%*c", &act, &x, &y);
			if(act == 'D'){
				Union(x, y+n);
				Union(x+n, y);
			}
			else if(act == 'A'){
				if(same(x, y))
					printf("In the same gang.\n");
				else if(same(x, y+n))
					printf("In different gangs.\n");
				else
					printf("Not sure yet.\n");
			}
		}
	}
	return 0;
}
