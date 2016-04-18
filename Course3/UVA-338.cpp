#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> print;

void get_dash_line(int n);
void adjust_space(int max_len);
string int_to_str(int &num);
string add(string a, string b);

int main(){
	int dash_size, carry, cnt, i, j, gap;
	char line[100], str1[20], str2[20];
	string a, b, c, d, dash_line, result;

	while(cin.getline(line, sizeof(line))){
		if(line[0]== '0' && strlen(line)==1) break;
		sscanf(line,"%s %s", str1, str2);
		print.clear();
		a = str1, b = str2, carry = 0, cnt = 0, result = "0";
		dash_size = max(a.size(),b.size()), i = b.size()-1, j = a.size()-1;
		print.push_back(a);
		print.push_back(b);
		get_dash_line(dash_size);
		gap = print.size();

		while(i >= 0){
			int mult = (a[j]-'0') * (b[i]-'0') + carry;
			carry = mult / 10, mult %= 10;

			if(mult > 0)
				c = int_to_str(mult) + c;

			if(j > 0) j--;
			else{
				if(carry > 0)
					c = int_to_str(carry) + c;
				j = a.size()-1, carry = 0, d = c;

				for(int k = 0 ; k < b.size()-1-i; k++){
					d += "0";
					c += " ";
				}

				if(mult > 0){
					print.push_back(c);
					result = add(result, d);
				}
				c.clear(), d.clear();
				i--;
			}
		}

		int max_len = max(max(a.size(), b.size()), result.size());
		adjust_space(max_len);
		gap = print.size() - gap;
		if(gap > 1)
			get_dash_line(max_len);

		print.push_back(result);
		for(int i = 0 ; i < print.size() ; i++){
			if(gap == 1 && i == 3) continue;
			else if(i <= 2 || i == print.size()-1)
				printf("%*s\n", max_len, print[i].c_str());
			else
				printf("%s\n", print[i].c_str());
		}
		printf("\n");
		result.clear();
	}
	return 0;
}

void get_dash_line(int n){
	string dash_line;
	while(n--) dash_line += "-";
	print.push_back(dash_line);
}

void adjust_space(int max_len){
	for(int i = 3 ; i < print.size() ; i++){
		int gap = max_len - print[i].size(), size;
		for(int j = 0 ; j < gap ; j++)
			print[i] = " " + print[i];
		size = print[i].size()-1;
		for(int j = size ; j >= 0 ; j--){
			if(print[i][j] == ' ')
				print[i].erase(print[i].begin()+j);
			else break;
		}
	}
}

string int_to_str(int &num){
	string s;
	stringstream str(s);
	str << num;
	return str.str();
}

string add(string a, string b){
	string add1 = (a.size() >= b.size())? a : b;
	string add2 = (a.size() < b.size())? a : b;
	int add, carry = 0, gap = add1.size()-add2.size(), size = add1.size()-1;
	for(int i = 0 ; i < gap ; i++)
		add2 = "0" + add2;

	for(int i = size ; i >= 0 ; i--){
		add = (add1[i]-'0') + (add2[i]-'0') + carry;
		carry = add/10;
		add1[i] = add%10 + '0';
		if(i == 0 && carry > 0)
			add1 = int_to_str(carry) + add1;
	}
	return add1;
}
