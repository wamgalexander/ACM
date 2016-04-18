#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct{
	int w, IQ, id;
}ELE;

bool cmp (ELE a, ELE b){
	if(a.w < b.w)
		return true;
	else if(a.w == b.w)
		return a.IQ > b.IQ;
	else return false;
}

int main()
{
	vector<ELE> E;
	ELE tmp;
	int cnt = 0, dp[1005] = {0};
	while(scanf("%d%d", &tmp.w, &tmp.IQ)!=EOF){
		tmp.id = cnt + 1;
		E.push_back(tmp);
		cnt++;
	}

	sort(E.begin(), E.end(), cmp);

	for(int i = 0 ; i < cnt ; ++i) dp[i] = 1;

	for(int i = cnt - 1 ; i >= 0 ; --i)
		for(int j = i - 1 ; j >= 0 ; --j)
			if(E[j].IQ > E[i].IQ && E[j].w != E[i].w)
				if(dp[j] < dp[i] + 1)
					dp[j] = dp[i] + 1;

	int len = *(max_element(dp, dp + cnt)), now = len;
	printf("%d\n", len);

	for(int i = 0 ; i < cnt ; ++i)
		if(dp[i] == now){
			printf("%d\n", E[i].id);
			now--;
		}

	return 0;
}
