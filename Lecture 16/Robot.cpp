#include<iostream>
#include<algorithm>
using  namespace std;

int Noise(string &s) {
	int c = 0;
	int n = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 's') {
			c++;
		} else {
			n += c;
		}
	}
	return n;
}


bool compare(string &a, string &b) {
	string ab = a + b;
	string ba = b + a;

	if (Noise(ab) > Noise(ba)) {
		return true;
	} else {
		return false;
	}
}

int main() {
	int n; cin >> n;

	string v[n];

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v, v + n, compare);

	string f = "";


	for (string x : v) {
		f = f + x;
	}

	cout << Noise(f) << endl;
}












