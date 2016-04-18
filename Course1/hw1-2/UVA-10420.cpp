#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int n;
	string country[2005], name;
	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		cin >> country[i];
		getline(cin, name);
	}

	sort(country, country + n);

	for(int i = 0 ; i < n ; i++){
		int j, cnt = 0;
		for(j = i ; j < n ; j++){
			if(country[i] != country[j])
				break;
			cnt++;
		}

		printf("%s %d\n", country[i].c_str(), cnt);
		i = j-1;
	}

	return 0;
}
