#include<iostream>
#include<bitset>
using  namespace std;
const int N = 1e5 + 10;

/*
	Q. You have to Print Prime Number from
	   2 to N.
	Actual Time : O(n*log(log(n)))

	bool variable: 1 byte : 8 bits

	Prime[N]: N byte: 8*N bits.

	bitset<N>Prime; N bits.

	Prime[i]=0/1. (Only bits)


*/

// bool Prime[N] {0};
bitset<N>Prime;//Intially Initialised with 0.

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