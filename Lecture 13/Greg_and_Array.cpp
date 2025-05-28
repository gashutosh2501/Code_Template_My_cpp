#include<iostream>
using  namespace std;
int n, m, k;
const int N = 1e5 + 3;
int a[N] {0}, operation_count[N] {0}, difference[N] {0};
int l[N] {0}, r[N] {0}, d[N] {0};


int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= m; i++) {
		cin >> l[i] >> r[i] >> d[i];
	}


	while (k--) {

		int x, y;
		cin >> x >> y;
		//Operations ki query ko resolve karna hain.
		operation_count[x] += 1;
		operation_count[y + 1] -= 1;
	}

	//Operation count ka prefix lo.

	for (int i = 1; i <= m + 1; i++) {
		operation_count[i] = operation_count[i - 1] +
		                     operation_count[i];
	}

	// for (int i = 1; i <= m; i++) {
	// 	cout << operation_count[i] << " ";
	// }

	// cout << endl;

	for (int i = 1; i <= n + 1; i++) {
		//I want to apply operation 1 operation_count[1] times and so on.

		difference[l[i]] += ((operation_count[i]) * d[i]);
		difference[r[i] + 1] -= ((operation_count[i]) * d[i]);
	}



	for (int i = 1; i <= n + 1; i++) {
		difference[i] = difference[i - 1] + difference[i];
	}


	for (int i = 1; i <= n + 1; i++) {
		difference[i] += a[i];
	}

	for (int i = 1; i <= n; i++) {
		cout << difference[i] << " ";
	}

	cout << endl;



}
