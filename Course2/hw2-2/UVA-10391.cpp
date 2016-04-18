#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    string line, s1, s2;
    set<string> Set;
    while(cin >> line)
        Set.insert(line);
    for(set<string>::iterator i = Set.begin(); i != Set.end(); i++) {
        int len = (*i).length();
        for(int j = 0; j < len-1; j++) {
            s1 = (*i).substr(0, j+1);
            s2 = (*i).substr(j+1, len-j);
            if(Set.find(s1) != Set.end() && Set.find(s2) != Set.end()) {
                cout << (*i) << endl;
                break;
            }
        }
    }
    return 0;
}
