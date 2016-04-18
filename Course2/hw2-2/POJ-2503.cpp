#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;

int main(){
	char str[30], s1[30], s2[30];
	map<string, string> dic;
	while(gets(str)){
		if(strlen(str)==0) break;
		sscanf(str,"%s %s", s1, s2);
		dic[s2] = s1;
	}

	while(gets(str)){
		if(dic[str].length()==0)
			printf("eh\n");
		else
			printf("%s\n", dic[str].c_str());
	}

	return 0;
}
