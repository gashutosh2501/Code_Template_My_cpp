#include<iostream>
#include<vector>
using  namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int Last_Digit[10];//Frequency Array for Last digit

		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			x %= 10;
			if (Last_Digit[x] < 3) {
				Last_Digit[x]++;
			}
		}

		vector<int>elements;

		for (int i = 0; i < 10; i++) {
			int Element = i;
			int freq = Last_Digit[i];
			while (freq--) {
				elements.push_back(i);
			}
		}

		//Apply Brute force

		for (int i = 0; i < elements.size(); i++) {
			for (int j = i + 1; j < elements.size(); j++) {
				for (int k = j + 1; k < elements.size(); k++) {
					if ((elements[i] + elements[j] + elements[k]) % 10 == 3) {
						cout << "YES" << endl;
						return 0;
					}
				}
			}
		}

		cout << "NO" << endl;

	}

}










