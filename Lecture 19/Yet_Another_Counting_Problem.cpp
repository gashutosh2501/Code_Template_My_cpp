#include<iostream>
using  namespace std;
const int N = 0;
#define int long long


int32_t main() {
	int t;
	cin >> t;

	while (t--) {
		int a, b, q;
		cin >> a >> b >> q;

		/*
			Flag[i]: Represents current i
			as a value satisfies the condition or
			not.

			Condition: (i%a)%b!=(i%b)%a;

			Pre[i]: No of values that satisfies
			the above condition in the range
			[0,i];
		*/
		int flag[40001] {0};
		int pre[40001] {0};

		for (int i = 0; i < (a * b); i++) {
			if (((i % a) % b) != ((i % b) % a)) {
				flag[i] = 1;
			}
			if (i == 0) {
				pre[i] = flag[i];
			} else {
				pre[i] = pre[i - 1] + flag[i];
			}
		}

		int CL = 0;//This represents no of x that satisfies the condition in the range [0,L-1].
		int CR = 0;//This represents no of x that satisfies the condition in the range [0,R].

		while (q--) {

			int l, r;
			cin >> l >> r;

			l--;

			//We are finding the value of CL.

			int m = l / (a * b);
			int n = l % (a * b);

			CL = (m * pre[(a * b) - 1]) + pre[n];

			m = r / (a * b);
			n = (r % (a * b));

			CR = (m * pre[(a * b) - 1]) + pre[n];

			cout << CR - CL << " ";

		}
		cout << endl;
	}
}
























