#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 50000;
const int INF = 0x3f3f3f3f;

struct Node{
	int l, r;
	int min, max;
	Node *left, *right;
};

Node tree[MAXN << 1];
int num[MAXN], ans_max, ans_min;

int nNodeCnt = 0;
void build(Node *rt, int l, int r){
	rt->l = l;
	rt->r = r;
	if(l == r){
		rt->min = rt->max = num[l];
		return ;
	}

	nNodeCnt++;
	rt->left = tree + nNodeCnt;
	nNodeCnt++;
	rt->right = tree + nNodeCnt;

	int m = (l + r) >> 1;
	build(rt->left, l, m);
	build(rt->right, m + 1, r);
	rt->max = max(rt->left->max, rt->right->max);
	rt->min = min(rt->left->min, rt->right->min);
}

void query(Node *rt, int l, int r){
	if(rt->l == l && rt->r == r){
		ans_max = ans_max > rt->max ? ans_max : rt->max;
		ans_min = ans_min < rt->min ? ans_min : rt->min;
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
}


int main(){
	int n, m, l, r;
	memset(tree, 0 , sizeof(tree));
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &num[i]);
	}
	build(tree, 1, n);
	
	for(int i = 0; i < m; ++i){
		scanf("%d%d", &l, &r);
		ans_max= 0, ans_min = INF;
		query(tree, l, r);
		printf("%d\n", ans_max - ans_min);
	}

	return 0;
}
