#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<numeric>
#include<bitset>
using  namespace std;
const int N = 1e5;
#define int long long

void Calculate_Totient() {
	bitset<N>pr;
	vector<int>tot(N);

	for (int i = 2; i * i <= N; i++) {
		if (pr[i] == 0) {
			for (int j = i * i; j <= N; j += i) {
				pr[j] = 1;
			}
		}
	}

	iota(tot.begin(), tot.end(), 0);

	for (int i = 2; i <= N; i++) {
		if (pr[i] == 0) {
			for (int j = i; j < N; j += i) {
				//Formulae
				tot[j] /= i;
				tot[j] *= (i - 1);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << i << " " << tot[i] << endl;
	}
}

int32_t main() {
	Calculate_Totient();
}













