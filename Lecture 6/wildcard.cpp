#include<iostream>
using  namespace std;


class Solution {
public:

	bool Solve(int i, int j, string &s, string &p, int (*dp)[2001]) {

		if (dp[i][j] != -1) {
			return dp[i][j];
		}

		if ( i == 0 and j == 0) {
			return true;
		}

		if (j == 0 and i > 0) {
			return 0;
		}

		if (i == 0 and j > 0) {
			while (j > 0) {
				if (p[j - 1] != '*') {
					return false;
				}
				j--;
			}

			return true;
		}



		if (s[i - 1] == p[j - 1] or p[j - 1] == '?') {
			return dp[i][j] = Solve(i - 1, j - 1, s, p, dp);
		} else if (p[j - 1] == '*') {
			int Op1 = Solve(i - 1, j, s, p, dp);
			int Op2 = Solve(i, j - 1, s, p, dp);
			return dp[i][j] = (Op1 or Op2);
		}

		return dp[i][j] = false;

	}

	bool isMatch(string s, string p) {
		int n = s.length();
		int m = p.length();

		int dp[2001][2001];
		memset(dp, -1, sizeof(dp));

		return Solve(n, m, s, p, dp);
	}
};




class Solution2 {
public:

	bool isMatch(string s, string p) {
		int n = s.length();
		int m = p.length();

		int dp[2001][2001];

		dp[0][0] = 1;

		for (int j = 1; j <= m; j++) {
			if (p[j - 1] == '*') {
				dp[0][j] = dp[0][j - 1];
			}
		}

		for (int i = 1; i <= n; i++) {
			dp[i][0] = 0;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {

				if (s[i - 1] == p[j - 1] or p[j - 1] == '?') {
					dp[i][j] = dp[i - 1][j - 1];
				} else if (p[j - 1] == '*') {
					dp[i][j] = (dp[i - 1][j] or dp[i][j - 1]);
				} else {
					dp[i][j] = 0;
				}
			}
		}
		return dp[n][m];
	}
};

int main() {



}







