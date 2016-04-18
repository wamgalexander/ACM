#include <cstdlib>
#include <cstdio>
#include <cstring>

int map[256];
int get_tel_num(char str[]){
	int num = 0;
	for(int i = 0 ; i < strlen(str) ; i++){
		if(str[i] >= '0' && str[i] <= '9')
			num = num*10 + (str[i] - '0');
		else if(str[i] >= 'A' && str[i] <= 'Y' && str[i]!= 'Q')
			num = num*10 + map[str[i]];	
	}

	return num;
}

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main(){
	int case_num, tel_num[100001];
	char str[100];

	// build tel map
	map['A'] = map['B'] = map['C'] = 2;
    map['D'] = map['E'] = map['F'] = 3;
    map['G'] = map['H'] = map['I'] = 4;
    map['J'] = map['K'] = map['L'] = 5;
    map['M'] = map['N'] = map['O'] = 6;
    map['P'] = map['R'] = map['S'] = 7;
    map['T'] = map['U'] = map['V'] = 8;
    map['W'] = map['X'] = map['Y'] = 9;

	scanf("%d", &case_num);
	for(int i = 0 ; i < case_num ; i++){
		scanf("%s", str);
		tel_num[i] = get_tel_num(str);
	}

	tel_num[case_num+1] = 0;
	qsort((void*) tel_num, case_num, sizeof(int), cmp);

	int no_duplicate = 0, cnt = 1;

	for(int i = 0 ; i < case_num+1 ; i++){
		if(tel_num[i] == tel_num[i+1]) cnt++;
		else if(cnt > 1){
			no_duplicate = 1;
			printf("%03d-%04d %d\n", tel_num[i]/10000, tel_num[i]%10000, cnt);
			cnt = 1;
		}
	}

	if(!no_duplicate)
		printf("No duplicates.\n");

	return 0;
}