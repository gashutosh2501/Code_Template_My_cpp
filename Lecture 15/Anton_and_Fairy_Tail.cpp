#include<iostream>
#define int long long
using  namespace std;
int n, m;

void Solve() {

	int s = 0;
	int e = 1e10;

	if (n <= m) {
		cout << n << endl;
		return;
	}

	int ans = -1;
	int value = n - m;

	while (s <= e) {
		int mid = (s + e) / 2;
		int t = mid * (mid + 1) / 2;
		if (value <= t) {
			ans = mid;
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}

	cout << ans + m << endl;
}



int32_t main() {
	cin >> n >> m;
	Solve();
}