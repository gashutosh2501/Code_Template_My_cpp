#include<iostream>
#include<vector>
#include<iomanip>
#include<cstring>
using  namespace std;
int dp[12][12];

vector<int>s;
int n;

int Solve(int pos = 0, int prev = 0, string temp = "") {

	if (pos == n) {
		//cout << temp << endl;
		return 1;
	}

	if (dp[pos][prev] != -1) {
		return dp[pos][prev];
	}
	int ans = 0;

	for (int j = 0; j < s.size(); j++) {
		if (prev == 0 or (abs(prev - s[j]) <= 2)) {
			ans += Solve(pos + 1, s[j], temp + to_string(s[j]));
		}
	}

	return dp[pos][prev] = ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> m >> n;
		s.resize(m);
		for (int i = 0; i < m; i++) {
			cin >> s[i];
		}
		memset(dp, -1, sizeof(dp));
		cout << Solve() << endl;
	}
}