#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#define MAX 100
using namespace std;
vector<char> ans, edge[MAX];
int visit[MAX] = {0}, node[MAX] = {0};

void DFS(char n);
int main()
{
	string a, b;
	cin >> a;
	while (cin >> b && b != "#") {
		int L = (a.size() > b.size()) ? b.size() : a.size();
		for (int i = 0; i < L; i++) {
			if (node[a[i]] == 0) node[a[i]] = 1;
			if (node[b[i]] == 0) node[b[i]] = 1;
			if (b[i] != a[i]) {
				edge[a[i]].push_back(b[i]);
				node[b[i]] = 2;
				break;
			}
		}
		a = b;
	}

	for (char i = 'A'; i <= 'Z'; i++)
		if (node[i] == 1)
			DFS(i);

	for (auto i = ans.rbegin(); i != ans.rend(); i++)
		printf("%c", *i);
	printf("\n");

	return 0;
}

void DFS(char c)
{
	if (visit[c] == 1) return;
	visit[c] = 1;
	for (char next : edge[c])
		if (visit[next] != 2)
			DFS(next);
	visit[c] = 2;
	ans.push_back(c);
}
