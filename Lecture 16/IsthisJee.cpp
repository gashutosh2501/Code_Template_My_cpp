#include<iostream>
#include<math.h>
#include<iomanip>
using  namespace std;
#define PI 3.1415926

double Function(double x, double b, double c) {
	return ((x * x + b * x + c) / sin(x));
}

double Derivative(double x, double b, double c) {
	return ((2 * x + b) * (sin(x)) - cos(x) * (x * x + b * x + c));
}


double IsThisJee(double b, double c) {
	double s = 0;
	double e = PI / 2;

	int count = 0;
	double ans = -1;

	while (s <= e) {

		double mid = (s + e) / 2;
		double value = Derivative(mid, b, c);

		if (value < 0) {
			ans = mid;
			s = mid;
		} else {
			ans = mid;
			e = mid;
		}
		count++;

		if (count == 100) {
			break;
		}
	}
	return ans;
}

double IsThisJee2(double b, double c) {

	double s = 0;
	double e = PI / 2;


	while (e - s > 1e-6) {
		double m1 = s + (e - s) / 3;
		double m2 = e - (e - s) / 3;

		if (Function(m1, b, c) > Function(m2, b, c)) {
			s = m1;
		} else if (Function(m1, b, c) < Function(m2, b, c)) {
			e = m2;
		} else {
			s = m1, e = m2;
		}
	}

	return s;
}


int main() {
	int t;
	cin >> t;

	while (t--) {
		double b, c;
		cin >> b >> c;

		double ans = IsThisJee(b, c);
		cout << fixed << setprecision(9) << Function(ans, b, c) << endl;

		double ans2 = IsThisJee2(b, c);
		cout << fixed << setprecision(9) << Function(ans2, b, c) << endl;
	}
}