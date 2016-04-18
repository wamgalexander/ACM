#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
	long long i,case_num, ans = 0, location[10010] = {0};
	scanf("%lld", &case_num);

	for(i = 0 ; i < case_num ; i++)
		scanf("%lld", &location[i]);

	sort(location, location+case_num);
	for(i = 0 ; i < case_num ; i++)
		ans += (case_num-1-i) * (location[case_num-1-i] - location[i]);

	printf("%lld", 2*ans);
	return 0;
}