#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char input[100], output[100];
int cnti[26], cnto[26], cmp;

int main()
{
    while(scanf("%s%s", output, input) == 2){
        memset(cnti, 0, sizeof(cnti));
        memset(cnto, 0, sizeof(cnto));
        for(int i = 0; i < strlen(input); i++) 
            cnti[input[i]-'A']++;
        for(int i = 0; i < strlen(output); i++) 
            cnto[output[i]-'A']++;

        sort(cnti, cnti + 26);
        sort(cnto, cnto + 26);
        cmp = 1;
        for(int i = 0; i < 26; i++){
            if(cnti[i] != cnto[i]){
                cmp = 0;
                break;
            }
        }
            
        if(cmp) printf("YES");
        else printf("NO");
    }
    return 0;
}