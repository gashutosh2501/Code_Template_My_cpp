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

int main() {
	int n, m;
	cin >> n >> m;
	//cout << n << m << endl;
	DSU g(n);

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		g.UnionU(x, y);
	}

	cout << g.components << endl;

}
















