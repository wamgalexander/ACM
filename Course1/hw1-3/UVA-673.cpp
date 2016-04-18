#include <cstdio>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	int n, correct;
	string str;
	stack <char> s;

	scanf("%d\n", &n);
	for(int i = 0 ; i < n ; i++){
		correct = 1;
		getline(cin, str);
		while(!s.empty()) s.pop();
		for(int j = 0 ; j < str.length() ; j++){
			if(str[j] == '('|| str[j] == '[' )
				s.push(str[j]);
			else if(str[j] == ')'){
				if(s.empty() || s.top() != '('){
					correct = 0;
					break;
				}
				s.pop();
			}
			else if(str[j] == ']'){
				if(s.empty() || s.top() != '['){
					correct = 0;
					break;
				}
				s.pop();
			}
		}

		if(!s.empty())
			correct = 0;
		printf("%s\n", correct ? "Yes" : "No");
	}
	return 0;
}
