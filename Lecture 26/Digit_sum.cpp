#include<bits/stdc++.h>
using  namespace std;
#define int long long


int dp[20][2][180];
//Computations: 20*2*180*10
//Space: 20*2*180

int Solve(string a, int pos = 0, int tight = 1, int sum = 0) {

	if (pos == a.length()) {
		return sum;
	}

	if (dp[pos][tight][sum] != -1) {
		return dp[pos][tight][sum];
	}

	int ans = 0;
	if (tight == 1) {

		int value = (a[pos] - '0');
		for (int i = 0; i <= value; i++) {
			if (i == value) {
				ans += Solve(a, pos + 1, 1, sum + i);
			} else {
				ans += Solve(a, pos + 1, 0, sum + i);
			}
		}
	} else {
		for (int i = 0; i <= 9; i++) {
			ans += Solve(a, pos + 1, 0, sum + i);
		}
	}

	dp[pos][tight][sum] = ans;
	return ans;
}


int32_t main() {
	int l, r;
	cin >> l >> r;
	l--;
	string a = to_string(l);
	string b = to_string(r);
	memset(dp, -1, sizeof(dp));
	int p = Solve(a);
	memset(dp, -1, sizeof(dp));
	int q = Solve(b);
	cout << q - p << endl;
}




