#include<iostream>
#include<cstring>
#include<iomanip>
using  namespace std;

// int dp[pos][tight][flag];
int dp[11][2][2];

int Solve(string s, int pos = 0, int tight = 1, int flag = 0) {

	if (pos == s.length()) {
		if (flag == 1) {
			return 1;
		} else {
			return 0;
		}
	}

	if (dp[pos][tight][flag] != -1) {
		return dp[pos][tight][flag];
	}

	int ans = 0;
	if (tight == 1) {

		int value = s[pos] - '0';

		for (int i = 0; i <= value; i++) {

			int f = flag;
			if (i == 3) {
				f = 1;
			}

			if (i == value) {
				ans += Solve(s, pos + 1, 1, f);
			} else {
				ans += Solve(s, pos + 1, 0, f);
			}
		}

	} else {
		for (int i = 0; i <= 9; i++) {
			int f = flag;
			if (i == 3) {
				f = 1;
			}
			ans += Solve(s, pos + 1, 0, f);
		}
	}

	return dp[pos][tight][flag] = ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string a = to_string(n);
		memset(dp, -1, sizeof(dp));
		cout << n - Solve(a) << endl;
	}
}