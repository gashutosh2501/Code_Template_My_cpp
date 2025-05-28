#include<iostream>
#include<vector>
using  namespace std;
class DSU {
public:
	vector<int>SP;
	vector<int>rank;
	int components;

	//Constructor
	DSU(int n) {
		SP.resize(n, -1);
		rank.resize(n, 1);
		components = n;
	}

	int FindS(int node) {
		//Return me the superparent.
		if (SP[node] == -1) {
			return node;
		}
		//Path Compression
		return SP[node] = FindS(SP[node]);
	}

	void UnionU(int x, int y) {
		//Union By Rank
		int S1 = FindS(x);
		int S2 = FindS(y);

		if (S1 != S2) {
			//Union Them.
			if (rank[S1] < rank[S2]) {
				SP[S1] = S2;
				rank[S2] += rank[S1];
			} else {
				SP[S2] = S1;
				rank[S1] += rank[S2];
			}
			components--;
		}
	}
};

int n;
string str[2 * 100004];

int main() {

	DSU g(26);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		str[i] = s;

		//Now make the union. I am Iterating over the input string
		for (int j = 0; j < str[i].length() - 1; j++) {
			g.UnionU(s[j] - 'a', s[j + 1] - 'a');
		}
	}

	int count[26] {0};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < str[i].length(); j++) {
			count[g.FindS(str[i][j] - 'a')]++;
		}
	}

	int ans = 0;
	for (int i = 0; i < 26; i++) {
		if (count[i] > 0) {
			ans++;
		}
	}

	cout << ans << endl;
}





































