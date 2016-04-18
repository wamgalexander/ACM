#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 10000 + 100;
const int INF = 0x3f3f3f3f;

vector<int> bounds;
map<int, int> hash;
bool isVisible = false;

struct Post{
	int l, r;
};
Post posters[MAXN];

struct Node{
	int l, r;
	bool isCovered;
	Node *left, *right;
};

Node tree[MAXN << 3];

int nNodeCnt = 0;
void build(Node *rt, int l, int r){
	rt->l = l;
	rt->r = r;
	rt->isCovered = false;
	if(l == r){
		return ;
	}
	nNodeCnt++;
	rt->left = tree + nNodeCnt;
	nNodeCnt++;
	rt->right = tree + nNodeCnt;

	int m = (l + r) >> 1;
	build(rt->left, l, m);
	build(rt->right, m + 1, r);
}

void query(Node *rt, int l, int r){
	if(rt->isCovered)return ;

	if(rt->l == l && rt->r == r){
		rt->isCovered = true;
		isVisible = true;
		return ;
	}

	int m = (rt->l + rt->r) >> 1;
	if(r <= m){
		query(rt->left, l, r);
	}else if(l > m){
		query(rt->right, l, r);
	}else{
		query(rt->left, l, m);
		query(rt->right, m + 1, r);

	}

	if(rt->left->isCovered && rt->right->isCovered){
		rt->isCovered = true;
	}
}

int main(){
	int testcases, n;
	scanf("%d", &testcases);
	for(int testcase = 0; testcase < testcases; ++testcase){
		scanf("%d", &n);
		bounds.clear();
		for(int i = 0; i < n; ++i){
			scanf("%d%d", &posters[i].l, &posters[i].r);
			bounds.push_back(posters[i].l);
			bounds.push_back(posters[i].r);
		}
		sort(bounds.begin(), bounds.end());
		bounds.erase(unique(bounds.begin(), bounds.end()), bounds.end());

		int nInterval = 1, nCnt = bounds.size();
		for(int i = 0; i < nCnt; ++i){
			hash[bounds[i]] = nInterval;
			if(i < nCnt - 1){
				if((bounds[i + 1] - bounds[i]) == 1){
					nInterval++;
				}else{
					nInterval += 2;
				}
			}
		}

		nNodeCnt = 0;
		build(tree, 1, nInterval);
		int ans_cnt = 0;
		for(int i = n - 1; i >= 0; --i){
			isVisible = false;
			query(tree, hash[posters[i].l], hash[posters[i].r]);
			if(isVisible) ans_cnt++;
		}

		printf("%d\n", ans_cnt);
	}

	return 0;
}
