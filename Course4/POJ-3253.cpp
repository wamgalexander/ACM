#include <cstdio>
#include <queue>
using namespace std;
typedef long long int LLT;

int main()
{
	LLT N, L, sum;
	while (scanf("%lld", &N) != EOF) {
		priority_queue<LLT, vector<LLT>, greater<LLT> > pq;
		for (LLT i = 0; i < N; i++) {
			scanf("%lld", &L);
			pq.push(L);
		}
		
		sum = 0;
		while (pq.size() > 1) {
			LLT tmp = pq.top();
			pq.pop();
			tmp += pq.top();
			pq.pop();
			sum += tmp;
			pq.push(tmp);
		}
		printf("%lld\n", sum);
	}
	return 0;
}
