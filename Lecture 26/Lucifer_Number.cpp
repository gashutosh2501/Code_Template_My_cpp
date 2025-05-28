#include<iostream>
#include<iomanip>
#include<cstring>
using  namespace std;
#define int long long


int prime[] {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,
	    61, 67, 71, 73, 79, 83, 89, 97, 101, 107, 109
};

//dp[pos][tight][evn_sum][odd_sum]
int dp[12][2][60][60];

int IsPrime(int odd_sum, int even_sum, int len) {
	int diff;
	if (len % 2 == 0) {
		diff = even_sum - odd_sum;
	} else {
		diff = odd_sum - even_sum;
	}

	if (diff < 0) {
		return 0;
	} else {

		for (auto x : prime) {
			if (diff == x) {
				return 1;
			}
		}
		return 0;
	}
}

int Solve(string s, int pos = 0, int tight = 1, int odd_sum = 0,
          int even_sum = 0) {

	if (pos == s.length()) {
		return IsPrime(odd_sum, even_sum, s.length());
	}

	if (dp[pos][tight][odd_sum][even_sum] != -1) {
		return dp[pos][tight][odd_sum][even_sum];
	}

	int ans = 0;

	if (tight == 1) {
		int value = s[pos] - '0';
		for (int i = 0; i <= value; i++) {
			int odd = odd_sum, ev = even_sum;
			if (pos % 2 == 1) {
				odd += i;
			} else {
				ev += i;
			}

			if (i == value) {
				ans += Solve(s, pos + 1, 1, odd, ev);
			} else {
				ans += Solve(s, pos + 1, 0, odd, ev);
			}
		}
	} else {
		for (int i = 0; i <= 9; i++) {
			int odd = odd_sum, ev = even_sum;
			if (pos % 2 == 1) {
				odd += i;
			} else {
				ev += i;
			}
			ans += Solve(s, pos + 1, 0, odd, ev);
		}
	}

	return dp[pos][tight][odd_sum][even_sum] = ans;
}


int32_t main() {
	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;
		a--;
		string l = to_string(a);
		string r = to_string(b);
		memset(dp, -1, sizeof(dp));
		int ans1 = Solve(r);
		memset(dp, -1, sizeof(dp));
		int ans2 = Solve(l);
		cout << ans1 - ans2 << endl;
	}
}