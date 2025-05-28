#include<iostream>
using  namespace std;

class Node {
public:
	Node* left;//Indicates if Node has a child that represents bit 0.
	Node* right;//Indicates if Node has a child that represents bit 1.

	Node() {
		this->left = NULL;
		this->right = NULL;
	}
};

class Trie {
	Node * root;
public:
	Trie() {
		root = new Node();
	}

	void Insert(int n) {
		Node* current = root;

		for (int i = 31; i >= 0; i--) {
			// int ithBit = ((n >> i) & 1);
			int ithBit = (1 << i)&n;
			if (ithBit == 0) {//ith bit of n is 0.

				if (current->left == NULL) {
					Node* n = new Node();
					current->left = n;
				}

				current = current->left;

			} else {//ith bit of n is 1.

				if (current->right == NULL) {
					Node* n = new Node();
					current->right = n;
				}

				current = current->right;
			}
		}
	}

	int Solve(int n) {

		/*
			Find the maximum Possibl xor Involving n in
			just 1 xor operationusing trie.
		*/

		int ans = 0;
		Node* current = root;

		for (int i = 31; i >= 0; i--) {
			int ithBit = (n >> i) & 1;

			if (ithBit == 0) {
				/*
					ith bit of answer can be set to 1 if
					current->right exist karta hain.
				*/

				if (current->right != NULL) {
					//I have to set answer ke ander
					//ith bit ko 1.
					ans = ans | (1 << i);
					current = current->right;

				} else {

					//There is no way to make ith bit in
					//answer as 1.
					current = current->left;

				}


			} else {

				//ith bit of n is 1.

				if (current->left != NULL) {
					ans = ans | (1 << i);
					current = current->left;
				} else {
					current = current->right;
				}
			}
		}

		//cout << n << "^" << ((n ^ ans)) << " = " << ans << endl;
		return ans;
	}


	int MaxiXor(int *a, int n) {
		int maxixorsofar = 0;
		for (int i = 0; i < n; i++) {
			maxixorsofar = max(maxixorsofar, Solve(a[i]));
		}
		return maxixorsofar;
	}
};

int main() {
	int a[] {3, 10, 5, 25, 2, 8};
	Trie t;

	for (int i = 0; i < 6; i++) {
		t.Insert(a[i]);
	}

	cout << t.MaxiXor(a, 6) << endl;

}











