#include <cstdio>
using namespace std;

int main(){
	int a, b, carry = 0, cnt = 0;
	while(scanf("%d %d", &a, &b) != EOF && (a || b)){
		cnt = 0;
		carry = 0;
		while(a || b){
			carry = a%10 + b%10 + carry;
			a /= 10;
			b /= 10;
			carry /= 10;
			if(carry) cnt++;
		}

		if(cnt == 0) printf("No carry operation.\n");
		else if(cnt == 1) printf("1 carry operation.\n");
		else printf("%d carry operations.\n", cnt);
	}
	return 0;
}
