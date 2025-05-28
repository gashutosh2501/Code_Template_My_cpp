#include<iostream>
#define int long long
using  namespace std;
string s;
int nb, ns, nc;
int sb, ss, sc;
int pb, ps, pc;
int r;


int Solve() {

	int s = 0;
	int e = 1e12 + 100;
	int ans = -1;

	while (s <= e) {
		int mid = (s + e) / 2;
		// cout << mid << endl;
		//cout << s << " " << e << endl;
		int mb = ((sb * mid) - nb) * pb;
		if (mb <= 0) {
			mb = 0;
		}
		int ms = ((ss * mid) - ns) * ps;
		if (ms <= 0) {
			ms = 0;
		}
		int mc = ((sc * mid) - nc) * pc;
		if (mc <= 0) {
			mc = 0;
		}

		int Total = mb + ms + mc;
		//cout << Total << endl;

		if (Total <= r) {
			ans = mid;
			s = mid + 1;
		} else {
			e = mid - 1;
		}
	}

	return ans;

}



int32_t main() {
	cin >> s;
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> r;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'B') {
			sb++;
		} else if (s[i] == 'S') {
			ss++;
		} else {
			sc++;
		}
	}

	//cout << ss << " " << sb << " " << sc << endl;

	cout << Solve();
}









