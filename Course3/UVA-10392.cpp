#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#define MAX 1000000

using namespace std;
bool isPrime[MAX];
vector<long long int> prime;

void prime_table(){
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = 0;
	for(int i = 2 ; i < sqrt(MAX) ; i++){
		if(isPrime[i]){
			prime.push_back(i);
			for(int j = i + i ; j < sqrt(MAX) ; j += i)
				isPrime[j] = false;
		}
	}
}

void solve(long long int value){
	for(int i  = 0 ; i < prime.size() ; i++){
			while(value%prime[i] == 0){
				printf("    %lld\n", prime[i]);
				value /= prime[i];
			}
	}

	if(value > 1) printf("    %lld\n", value);
	printf("\n");
}

int main(){
	long long int n;
	prime_table();
	while(scanf("%lld", &n)!=EOF && n >= 0){
		solve(n);
	}
	return 0;
}
