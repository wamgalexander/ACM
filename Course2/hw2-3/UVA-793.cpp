#include <cstdio>
using namespace std;

int Set[1000001];

void init(int n);
int find(int x);
void Union(int x, int y);

int main(){
	int t, c;
	char line[105];
	scanf("%d", &t);
	while(t--){
		scanf("%d ", &c);
		init(c);

		char type;
		int x, y, S = 0, F = 0;

		while(gets(line) && line[0]!='\0'){
			sscanf(line,"%c %d %d", &type, &x, &y);

			if(type == 'c')
				Union(x, y);
			else{
				if(find(x) == find(y)) ++S;
				else ++F;
			}
		}
		printf("%d,%d\n", S, F);
		if(t) printf("\n");
	}
	return 0;
}

void init(int n){
	for(int i = 0 ; i <= n ; i++)
		Set[i] = i;
}

int find(int x){
	return (x == Set[x])? x : (Set[x] = find(Set[x]));
}

void Union(int x, int y){
	x = find(x), y = find(y);
	if(x != y)
		Set[y] = x;
}
