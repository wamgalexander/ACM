#include <cstdio>
#include <vector>
#include <sstream>
using namespace std;
int nets;
vector<int> Set;

void init(int n);
int find(int x);
void Union(int x, int y);

int main(){
	int t, n;
	char line[1000];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		init(n);
		nets = n;
		int x, y;
		while (getchar() != '\n');
		while (gets(line) && line[0] != '\0') {
	        stringstream str_in(line);
	        while (str_in >> x >> y) {
	        	Union(x, y);
	        }
	    }
		printf("%d\n", nets);
		if(t) printf("\n");
	}

	return 0;
}

void init(int n){
	Set.clear();
	for(int i = 0; i <= n ; i++)
		Set.push_back(i);
}

int find(int x){
	return (x == Set[x])? x : (Set[x] = find(Set[x]));
}

void Union(int x, int y){
	x = find(x), y = find(y);
	if(x != y){
		Set[x] = y;
		nets--;
	}
}
