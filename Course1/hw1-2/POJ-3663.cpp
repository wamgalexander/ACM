#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n, s, tmp, ans = 0, m = 0, len[20010];
	scanf("%d %d", &n, &s);
	for(int i = 0 ; i < n ; i++){
		scanf("%d", &tmp);
		if(tmp < s)
			len[m++] = tmp;
	}

	sort(len, len+m);
	for(int i = 0 ; i < m ; i++){
		for(int j = i+1 ; j < m ; j++){
			if( len[i] + len[j] <= s)
				ans++;
			else
				break;
		}
	}

	printf("%d", ans);
	return 0;
}
