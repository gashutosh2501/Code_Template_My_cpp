#include<iostream>
#include<unordered_set>
#include<vector>
#include <cstring>
using  namespace std;



class Solution {
public:

	bool Solve(int start, string &s, int *dp, unordered_set<string>&dic) {

		if (start == s.length()) {
			return true;
		}

		if (dp[start] != -1) {
			return dp[start];
		}

		for (int j = start; j < s.length(); j++) {

			string word = s.substr(start, j - start + 1);

			if (dic.count(word) == 1 and Solve(j + 1, s, dp, dic) == 1) {
				return dp[start] = true;
			}


		}

		return dp[start] = false;

	}


	bool wordBreak(string s, vector<string>&d) {

		unordered_set<string>dic(d.begin(), d.end());
		int dp[301];
		memset(dp, -1, sizeof(dp));
		return Solve(0, s, dp, dic);
	}

};


int main() {
	Solution s;

	string st;
	cin >> st;

	vector<string>d;
	string str;

	while (cin >> str) {
		d.push_back(str);
	}


	// for (auto x : d) {
	// 	cout << x << " ";
	// }

	cout << s.wordBreak(st, d) << endl;
}


