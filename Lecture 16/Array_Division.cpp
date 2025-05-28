#include<iostream>
#include<map>
using  namespace std;

//Easy : DO this using BS.

int main() {
	int n;
	cin >> n;

	int a[n];
	int sum = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	if (sum % 2 == 1) {
		cout << "NO" << endl;
		return 0;
	}

	sum /= 2;
	int prefix = 0;

	map<int, int>mp;

	for (int i = 0; i < n; i++) {
		prefix += a[i];
		mp[a[i]]++;

		if (mp[prefix - sum] > 0) {
			cout << "YES" << endl;
			return 0;
		}
	}

	mp.clear();


	int suffix = 0;

	for (int i = n - 1; i >= 0; i--) {
		suffix += a[i];
		mp[a[i]]++;

		if (mp[suffix - sum] > 0) {
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;

}