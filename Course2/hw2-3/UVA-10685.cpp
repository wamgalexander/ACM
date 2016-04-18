#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <utility>
#define MAX 5010
using namespace std;
typedef pair<int, int> II;

map<string, int> m;
map<string, int> ::iterator i;
vector<II> nature_set;

void init(int n);
int find(int x);
void Union(int x, int y);
int find_max_set(int n);

int main(){
	int c, r;
	while(scanf("%d %d", &c, &r)){
		if(!c && !r) break;
		init(c);
		string str1, str2;
		for(int i = 0 ; i < c ; i++){
			cin >> str1;
			m[str1] = i;
		}

		while(r--){
			cin >> str1 >> str2;
			Union(m[str1], m[str2]);
		}
		printf("%d\n", find_max_set(c));
	}
	return 0;
}

void init(int n){
	m.clear();
	for(int i = 0 ; i < n ; i++)
		nature_set.push_back(II(i, 1));
}

int find(int x){
	return (x == nature_set[x].first)? x : (nature_set[x].first = find(nature_set[x].first));
}

void Union(int x, int y){
	x = find(x), y = find(y);
	if(x != y){
		nature_set[x].first = y;
		nature_set[y].second += nature_set[x].second;
	}
}

int find_max_set(int n){
	int max = 0;
	for(int i = 0 ; i < n ; i++)
		if(nature_set[i].second > max) max = nature_set[i].second;
	return max;
}
