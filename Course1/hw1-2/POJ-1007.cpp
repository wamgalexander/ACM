#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct input{
    char str[51];
    int len;
}Input;

int Sort(char str[]){
    int i, j, cnt=0;
    for(i = 0 ; i < strlen(str); i++)
        for(j = i+1 ; j < strlen(str) ; j++)
            if(str[i] > str[j])
                cnt++;
    return cnt;
}

bool cmp(Input a, Input b){
    return (a.len < b.len)? true : false;
}

int main(){
    Input in[101];
    int i, str_len, case_num;

    scanf("%d %d", &str_len, &case_num);
    for(i = 0 ; i < case_num ; i++){
        scanf("%s", in[i].str);
        in[i].len = Sort(in[i].str);
    }

    sort(in,in+case_num, cmp);

    for(i = 0 ; i < case_num ; i++){
        printf("%s", in[i].str);
        if(i < case_num - 1)
            printf("\n");
    }

    return 0;
}
