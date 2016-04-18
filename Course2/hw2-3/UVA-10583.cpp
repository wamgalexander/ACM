#include <cstdio>
#include <set>
#include <vector>
using namespace std;
vector<int> Set;
int religion;

void init(int n);
int find(int x);
void Union(int x, int y);

int main(){
	int n, m, case_num = 1, x, y;
	while(scanf("%d %d", &n, &m) && (n || m)){
		init(n);
		religion = n;
		while (m--) {
			scanf("%d%d", &x, &y);
			Union(x, y);
		}
		printf("Case %d: %d\n", case_num++, religion);
	}
	return 0;
}

void init(int n){
	Set.clear();
	for(int i = 0 ; i < n ; i++)
		Set.push_back(i);
}

int find(int x){
	return (x == Set[x])? x : (Set[x] = find(Set[x]));
}

void Union(int x, int y){
	x = find(x), y = find(y);
	if(x != y){
		Set[x] = y;
		religion--;
	}
}
