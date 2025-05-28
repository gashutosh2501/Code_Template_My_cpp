#include<iostream>
#include<algorithm>
#include<vector>
using  namespace std;

// bool compare(int a, int b) {
// 	// if (a > b) {
// 	// 	return true;
// 	// } else {
// 	// 	return false;
// 	// }

// 	return a < b;
// }


bool compare(string x, string y) {

	string xy = x + y;
	string yx = y + x;

	if (xy > yx) {
		return true;
	} else {
		return false;
	}


}

int main() {

	// vector<int>v{10, 1, 2, 3, 18, 9, 12};

	// // sort(v.begin(), v.end(), greater<int>());
	// // sort(v.rbegin(), v.rend());

	// sort(v.begin(), v.end(), compare);


	// for (auto x : v) {
	// 	cout << x << ' ';
	// }

	int n;
	cin >> n;
	vector<string>v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), compare);

	for (auto x : v) {
		cout << x;
	}




	// for (int i = 0; i < n - 1; i++) {
	// 	for (int j = 0; j < n - i - 1; j++) {
	// 		if (compare(a[i],a[j])) {

	// 		}
	// 	}
	// }


}












