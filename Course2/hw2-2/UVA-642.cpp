#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int main(){
	string key, str;
	map < string , set<string> > dic;
	while(cin >> str && str != "XXXXXX"){
			key = str;
			sort(key.begin(), key.end());
			dic[key].insert(str);
	}

	while(cin >> str && str != "XXXXXX"){
		int valid = 0;
		sort(str.begin(), str.end());
		for(set<string>::iterator i = dic[str].begin() ; i != dic[str].end() ; i++){
			cout << *i << endl;
			valid = 1;
		}

		if(!valid) cout << "NOT A VALID WORD" << endl;
		cout << "******" << endl;
	}

	return 0;
}
