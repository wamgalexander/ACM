#include <iostream>
#include <string>
#include <vector>

#define MAX 110
#define L 2 // ←
#define U 1	// ↑
#define F 0 // ↖
using namespace std;

string s1[MAX], s2[MAX];
int LCS[MAX][MAX], pre[MAX][MAX];

int main()
{
	while (1) {
		int n = 1, m = 1;
		while (cin >> s1[n] && s1[n] != "#") ++n;
		while (cin >> s2[m] && s2[m] != "#") ++m;
		if (n == 1) return 0;
		for (int i = 1 ; i < n; ++i) {
			for (int j = 1 ; j < m ; ++j) {
				if (s1[i] == s2[j]) {
					LCS[i][j] = LCS[i-1][j-1] + 1;
					pre[i][j] = F;
				}
				else {
					if (LCS[i-1][j] > LCS[i][j-1]) {
						LCS[i][j] = LCS[i-1][j];
						pre[i][j] = U;
					}
					else {
						LCS[i][j] = LCS[i][j-1];
						pre[i][j] = L;
					}
				}
			}
		}

		vector<string *> ans;
		int i = n - 1, j = m - 1;
		while (i && j) {
			if (pre[i][j] == 0) {
				ans.push_back(&s1[i]);
				--i, --j;
			}
			else if (pre[i][j] == 1) --i;
			else --j;
		}
		if (!ans.empty()) {
			cout << **ans.rbegin();
			for (auto i = ans.rbegin() + 1 ; i != ans.rend() ; ++i)
				cout << ' ' << **i;
		}
		cout << endl;
	}

	return 0;
}
