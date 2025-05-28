#include<iostream>
#include<iomanip>
#include<cstring>
using  namespace std;
#define int long long

//dp[pos][sum][tight]
int dp[10][80][2];

int prime[] {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,
	    61, 67, 71, 73, 79, 83, 89, 97, 101, 107, 109
};

bool Check(int sum) {
	for (auto x : prime) {
		if (x == sum) {
			return 1;
		}
	}
	return 0;
}


int Solve(string s, int pos = 0, int sum = 0, int tight = 1) {

	if (pos == s.length()) {
		if (Check(sum) == 1) {
			return 1;
		} else {
			return 0;
		}
	}

	if (dp[pos][sum][tight] != -1) {
		return dp[pos][sum][tight];
	}
	int ans = 0;
	if (tight == 1) {
		int value = s[pos] - '0';
		for (int i = 0; i <= value; i++) {
			if (i == value) {
				ans += Solve(s, pos + 1, sum + i, 1);
			} else {
				ans += Solve(s, pos + 1, sum + i, 0);
			}
		}

	} else {
		for (int i = 0; i <= 9; i++) {
			ans += Solve(s, pos + 1, sum + i, 0);
		}
	}

	return dp[pos][sum][tight] = ans;
}


int32_t main() {
	int c;
	cin >> c;
	while (c--) {
		int l, r;
		cin >> l >> r;
		l--;
		string a = to_string(l);
		string b = to_string(r);
		memset(dp, -1, sizeof(dp));
		int ans1 = Solve(b);
		memset(dp, -1, sizeof(dp));
		int ans2 = Solve(a);
		cout << ans1 - ans2 << endl;
	}
}