#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int MAXN = 100000 + 10;
const int INF = 0x3f3f3f3f;

struct Node{
	int l, r;
	Node *left, *right;
	long long sum;
	long long inc;
};

Node Tree[MAXN << 1];
int num[MAXN];
long long ans_sum;

int nNodeCnt = 0;
void build(Node *rt, int l, int r){
	rt->l = l;
	rt->r = r;
	if(l == r){
		rt->inc = 0;
		rt->sum = num[l];
		return;
	}

	nNodeCnt++;
	rt->left = Tree + nNodeCnt;
	nNodeCnt++;
	rt->right = Tree + nNodeCnt;


	int m = (l + r) >> 1;
	build(rt->left, l, m);
	build(rt->right, m + 1, r);
	rt->sum = rt->left->sum + rt->right->sum;
}

void pushdown(Node *rt){
	if(rt->inc){
		rt->left->inc += rt->inc;
		rt->right->inc += rt->inc;
		rt->left->sum += (((rt->left->r - rt->left->l) + 1) * rt->inc);
		rt->right->sum += (((rt->right->r - rt->right->l) + 1) * rt->inc);
		rt->inc = 0;
	}
}

void query(Node *rt, int l, int r){
	if(rt->l == l && rt->r == r){
		ans_sum += rt->sum;
		return ;
	}

	pushdown(rt);

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

void update(Node *rt, int l, int r, long long inc){
	if(rt->l == l && rt->r == r){
		rt->inc += inc;
		rt->sum += (((rt->r - rt->l) + 1) * inc);
		return ;
	}
	
	pushdown(rt);

	int m = (rt->l + rt->r) >> 1;
	if(r <= m){
		update(rt->left, l, r, inc);
	}else if(l > m){
		update(rt->right, l, r, inc);
	}else{
		update(rt->left, l , m, inc);
		update(rt->right, m + 1, r, inc);
	}

	rt->sum = rt->left->sum + rt->right->sum;
}


int main(){
	int n, q;
	while(scanf("%d%d", &n, &q) == 2){
		for(int i = 1; i <= n; ++i){
			scanf("%d", &num[i]);
		}
		memset(Tree, 0, sizeof(Tree));
		build(Tree, 1, n);

		char cmd;
		int l, r;
		long long v;
		for(int i = 0; i < q; ++i){
			scanf(" %c", &cmd);
			scanf("%d%d", &l, &r);
			if(cmd == 'Q'){
				ans_sum = 0;
				query(Tree, l, r);
				printf("%lld\n", ans_sum);
			}else{
				scanf("%lld", &v);
				update(Tree, l, r, v);
			}
		}
	}
	return 0;
}
