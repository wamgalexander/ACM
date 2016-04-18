#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main(){
	int cnt = 0;
	string str;
	set<string> s;
	set<string> :: iterator i;
	while(cin >> str){
		if(cnt == 2) break;
		else if(str == "XXXXXX") cnt++;
		else if(cnt == 0)
			s.insert(str);
		else if(cnt == 1){
			bool valid = false;
			sort(str.begin(), str.end());

			do{
				i = s.find(str);
				if(i != s.end()){
					valid = true;
					cout << str << endl; 
				}
			}while(next_permutation(str.begin(), str.end()));

		
			if(!valid)
				printf("NOT A VALID WORD\n");
			printf("******\n");
		}
	}
}
