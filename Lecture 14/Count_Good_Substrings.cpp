#include<iostream>
using  namespace std;
string s;
#define int long long

void Count() {

	int POI_a = 0;
	int PEI_a = 0;

	int PEI_b = 0;
	int POI_b = 0;

	int even = 0, odd = 0;

	for (int i = 0; i < s.length(); i++) {
		odd++;
		char ch = s[i];
		if (i % 2 == 0) {
			//Even Index:
			if (ch == 'a') {
				odd += PEI_a;
				even += POI_a;
				PEI_a++;
			} else {
				odd += PEI_b;
				even += POI_b;
				PEI_b++;
			}
		} else {
			if (ch == 'a') {
				odd += POI_a;
				even += PEI_a;
				POI_a++;
			} else {
				odd += POI_b;
				even += PEI_b;
				POI_b++;
			}
		}
	}

	cout << even << " " << odd << endl;
}

int32_t main() {
	cin >> s;
	Count();
}