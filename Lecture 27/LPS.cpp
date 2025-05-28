#include<iostream>
#include<vector>
using  namespace std;


void SolveLPS(string &s, vector<int>&lps) {
	/*
		ans stores the longest length of
		prefix which is also suffix for the
		previous index.
	*/
	int pre = 0;
	lps[0] = 0;
	int suff = 1;
	while (suff < s.length()) {
		if (s[suff] == s[pre]) {
			pre++;
			lps[suff] = pre;
			suff++;
		} else {
			if (pre != 0) {
				pre = lps[pre - 1];
			} else {
				lps[suff] = 0;
				suff++;
			}
		}
	}
}

int main() {
	string s;
	cin >> s;
	vector<int>lps(s.length(), 0);

	SolveLPS(s, lps);

	for (auto x : lps) {
		cout << x << " ";
	}
}