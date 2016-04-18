#include <cstdio>

int main(){
	int num,n,m,i;
	scanf("%d", &num);

	double path_len[num];
	for(i = 0 ; i < num ; i++)
	{
		scanf("%d %d", &n, &m);
		path_len[i] = (n*m)%2 ? n*m+0.41 : n*m;
	} 

	for(i = 0; i < num ; i++)
		printf("Scenario #%d:\n%.2f\n\n", i+1, path_len[i]);

	return 0;
}