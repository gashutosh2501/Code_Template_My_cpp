#include<iostream>
using  namespace std;
const int N = 1e5 + 10;

/*
	Q. You have to Print Prime Number from
	   2 to N.
	Actual Time : O(n*log(log(n)))

*/

bool Prime[N] {0};

void Prime_Seive() {

	for (int i = 3; i * i <= N; i += 2) {
		if (Prime[i] == 0) {
			for (int j = i * i; j <= N; j += i) {
				Prime[j] = 1;
			}
		}
	}


	cout << 2 << " ";
	for (int i = 3; i <= N; i += 2) {
		if (Prime[i] == 0) {
			cout << i << " ";
		}
	}

}

int main() {
	Prime_Seive();
}