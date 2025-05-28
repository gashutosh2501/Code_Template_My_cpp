#include<iostream>
using  namespace std;
int k;
string st;
int freq[27] {0};


void Title() {

	int i = 0;
	int n = st.length();
	int j = n - 1;

	while (i < j) {
		if (st[i] == '?' and st[j] == '?') {
			i++, j--;
			continue;
		} else if (st[i] == '?' and st[j] != '?') {
			st[i] = st[j];
			freq[st[i] - 'a' + 1]++;
		} else if (st[i] != '?' and st[j] == '?') {
			st[j] = st[i];
			freq[st[i] - 'a' + 1]++;
		} else if (st[i] == st[j]) {
			freq[st[i] - 'a' + 1]++;
		} else {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
		i++;
		j--;
	}


	//Take care of Middle Element:

	if (i == j and st[i] != '?') {
		freq[st[i] - 'a' + 1]++;
	}


	//Second Pass from the center:

	while (i >= 0 and j < n) {

		//I want to find the largest
		//unused character.

		while (k > 1 and freq[k] > 0) {
			k--;
		}

		if (st[i] == '?' and st[j] == '?') {
			st[i] = st[j] = k + 'a' - 1;
			freq[k - 'a' - 1]++;
		}

		i--, j++;
	}

	if (k == 1 and freq[k] > 0) {
		cout << st << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
	}
}

int main() {

	cin >> k;
	cin >> st;

	Title();



}