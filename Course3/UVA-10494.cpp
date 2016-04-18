#include <cstdio>
#include <cstring>
#define MAX 10001
using namespace std;

char num[MAX];
long long int b,r;
char oper[2];

int main()
{
    while (scanf("%s %s %lld", num, oper, &b) != EOF){
		r = 0;
        int q[MAX], index = 0, start = 0;
        for (int i = 0 ; i < strlen(num) ; i++){
            r = r * 10 + (num[i] - '0');
            q[index++] = r / b;
            r = r % b;
        }

        if (oper[0] == '/'){
			for(int i = 0 ; i < index ; i++){
				if(q[i] == 0 && start == 1)
					printf("%d", q[i]);
            	else if(q[i] > 0){
					start = 1;
					printf("%d", q[i]);
				}
			}
            if (start == 0)
				printf("0");
            printf("\n");
        }
        else
            printf("%lld\n", r);
    }
    return 0;
}
