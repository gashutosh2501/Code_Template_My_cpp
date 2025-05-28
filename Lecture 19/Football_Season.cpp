#include<iostream>
using  namespace std;
const int N = 0;
int x, y, gcd;
#define int long long

int GCD(int x, int y) {
	if (y == 0) {
		return x;
	}
	return  GCD(y, x % y);
}

void EED(int a, int b) {
	if (b == 0) {
		x = 1;
		y = 0;
		gcd = a;
		return;
	}
	EED(b, a % b);

	int current_x = y;
	int current_y = x - (a / b) * y;

	x = current_x;
	y = current_y;
}

int MMI(int a, int m) {
	EED(a, m);
	return  (x + m) % m;
}




int32_t main() {
	int n, p, w, d;
	cin >> n >> p >> w >> d;

	int x, y, z;
	int g = GCD(w, d);

	if (p % g != 0) {
		cout << "-1" << endl;
		return 0;
	}

	if (n * w < p) {
		cout << "-1" << endl;
		return 0;
	}

	p /= g;
	d /= g;
	w /= g;


	//y Ki value ko find karo.
	y = ((p % w) * MMI(d, w)) % w;

	//x ki value ko find Karo.
	x = (p - (y * d)) / w;

	if (x + y > n) {
		cout << "-1" << endl;
		return 0;
	}

	if (x < 0) {
		cout << "-1" << endl;
		return 0;
	}

	//z Ki value ko find karo.
	z = n - x - y;

	cout << x << " " << y << " " << z << endl;

}






