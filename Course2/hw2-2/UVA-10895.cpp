#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> II;
typedef vector<II> VII;
vector<VII> matrix, tmatrix;

int main(){
	int m,n,k,tmp;

	while(scanf("%d %d", &m, &n)!=EOF){
		int col[n];
		matrix.assign(m, VII());
		tmatrix.assign(n, VII());

		for(int i = 0 ; i < m ; i++){
			scanf("%d", &k);
			for(int j = 0 ; j < k ; j++){
				scanf("%d", &tmp);
				col[j] = tmp;
			}

			for(int j = 0 ; j < k ; j++){
				scanf("%d", &tmp);
				matrix[i].push_back(II(col[j]-1 , tmp));
			}
		}

		for(int i = 0 ; i < m ; i++){
			for(int j = 0 ; j < matrix[i].size() ; j++){
				II v = matrix[i][j];
				tmatrix[v.first].push_back(II(i, v.second));
			}
		}

		printf("%d %d\n", n, m);
		for(int i = 0 ; i < n ; i++){
			printf("%d", tmatrix[i].size());
			for(int j = 0 ; j < tmatrix[i].size() ; j++)
					printf(" %d", tmatrix[i][j].first+1);
			printf("\n");

			for(int j = 0 ; j < tmatrix[i].size() ; j++){
				printf("%d", tmatrix[i][j].second);
				if(j < tmatrix[i].size()-1) printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
