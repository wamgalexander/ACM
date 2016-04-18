#include <algorithm>
#include <cstdio>
using namespace std;

char s[4][13];
int i[4];

int main(void)
{
	int max, tmp, size = 12;
	while( scanf("%s %s %s %s", s[0], s[1], s[2], s[3]) == 4){
		i[0] = 0;
		i[1] = 1;
		i[2] = 2;
		i[3] = 3;
		max = 0;
		do{
			for(int a = 1 ; a + 1 < size ; ++a){
				for(int b = a + 1 ; b + 1 < size ; ++b){
					for(int c = 1 ; c + 1 < size ; ++c){
						if(s[i[0]][a] != s[i[1]][c])
							continue;
						for(int d = 1 ; d + 1 < size ; ++d){
							if(s[i[0]][b] != s[i[2]][d])
								continue;
							for(int e = 1 ; c + e + 1 < size && d + e + 1 < size ; ++e){
								for(int f = 1 ; f + 1 < size ; ++f){
									if(f + b - a <= 0 || 11 <= f + b - a)
										continue;
									if(s[i[1]][c + e] != s[i[3]][f])
										continue;
									if(s[i[2]][d + e] != s[i[3]][f + b - a])
										continue;
									tmp = (e - 1) * (b - a - 1);
									if(tmp > max)
										max = tmp;
								}
							}
						}
					}
				}
			}
		}while(next_permutation(i, i + 4));
		printf("%d\n", max);
	}
	return 0;
}
