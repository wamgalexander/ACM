#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int MAXN = 10000 + 10;

vector<double> y;
map<double, int> hash;

struct Node{
	int l, r;
	Node *left, *right;
	double len;
	int covers;
};
Node tree[MAXN << 2];

struct Line{
	double x, y1, y2;
	bool isLeft;
};

vector<Line> lines;

int nNodeCnt = 0;

bool cmp (Line l1, Line l2){
	return l1.x < l2.x;
}

void insert(Node *rt, int l, int r){
	if(rt->l == l && rt->r == r){
		rt->len = y[r + 1] - y[l];
		rt->covers++;
		return ;
	}

	int m = (rt->l + rt->r) >> 1;
	if(r <= m){
		insert(rt->left, l, r);
	}else if( l > m){
		insert(rt->right, l, r);
	}else{
		insert(rt->left, l, m);
		insert(rt->right, m + 1, r);
	}

	if(rt->covers == 0)
		rt->len = rt->left->len + rt->right->len;
}

void remove(Node *rt, int l, int r){
	if(rt->l == l && rt->r == r){
		rt->covers--;
		if(rt->covers == 0){
			if(rt->l == rt->r){
				rt->len = 0;
			}else{
				rt->len = rt->left->len + rt->right->len;
			}
		}
		return ;
	}

	int m = (rt->l + rt->r) >> 1;
	if(r <= m){
		remove(rt->left, l, r);
	}else if(l > m){
		remove(rt->right, l, r);
	}else{
		remove(rt->left, l, m);
		remove(rt->right, m + 1, r);
	}

	if(rt->covers == 0){
		rt->len = rt->left->len + rt->right->len; 
	}
}

void build(Node *rt, int l, int r){
	rt->l = l;
	rt->r = r;
	rt->covers = 0;
	rt->len = 0;
	if(l == r) return ;
	nNodeCnt++;
	rt->left = tree + nNodeCnt;
	nNodeCnt++;
	rt->right = tree + nNodeCnt;

	int m = (l + r) >> 1;
	build(rt->left, l, m);
	build(rt->right, m + 1, r);
}

int main(){
	int n, testcases = 0;
	double x1, y1, x2, y2;
	int yCnt, lCnt; 
	while(true){
		scanf("%d", &n);
		if(n == 0) break;
		testcases = testcases + 1;
		yCnt = lCnt = 0;
		lines.clear();
		y.clear();
		for(int i = 0; i < n; ++i){
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			y.push_back(y1);
			y.push_back(y2);
			Line line1, line2;
			line1.x = x1;
			line1.y1 = y1;
			line1.y2 = y2;
			line1.isLeft = true;
			lines.push_back(line1);
			line2.x = x2;
			line2.y1 = y1;
			line2.y2 = y2;
			line2.isLeft = false;
			lines.push_back(line2);
		}
		sort(y.begin(), y.end());
		y.erase(unique(y.begin(), y.end()), y.end());
		yCnt = y.size();
		nNodeCnt = 0;
		build(tree, 0, yCnt - 1 - 1);
		sort(lines.begin(), lines.end(), cmp);
		lCnt = lines.size();
		double ans_area = 0.0;
		int nInterval = 0;
		hash.clear();
		for(int i = 0; i < yCnt; ++i){
			hash[y[i]] = nInterval++;
		}
		for(int i = 0; i < lCnt - 1; i++){
			int l = hash[lines[i].y1];
			int r = hash[lines[i].y2];
			if(lines[i].isLeft){
				insert(tree, l, r - 1);
			}else{
				remove(tree, l, r - 1);
			}
			ans_area += tree[0].len * (lines[i + 1].x - lines[i].x);
		}

		printf("Test case #%d\n", testcases);
		printf("Total explored area: %.2f\n\n", ans_area);
	}
	return 0;
}

