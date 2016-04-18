#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

void cnt_letter(string &s, int cnt[]){
  for(int i = 0 ; i < s.length() ; ++i)
    ++cnt[(int)(s[i]-'a')];
}

int main(){
  string a, b;
  while(getline(cin, a)){
    getline(cin, b);

    int cnt_a[30] = {0}, cnt_b[30] = {0};
    cnt_letter(a, cnt_a), cnt_letter(b, cnt_b);

    for(int i = 0 ; i < 26 ; ++i){
      int cnt = min(cnt_a[i], cnt_b[i]);
      for(int j = 0 ; j < cnt ; ++j)
        printf("%c", (char)(i+'a'));
    }
    printf("\n");
  }
  
  return 0;
}
