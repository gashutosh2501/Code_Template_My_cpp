/*
	Question: Given an Integer Array , Find the Maximum Xor Pair Value.
*/

#include<iostream>
using  namespace std;

class Node {
public:
	Node* left;//Indicates if Node has a child that represents bit 0.
	Node* right;//Indicates if Node has a child that represents bit 1.
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
			int ithBit = ((n >> i) & 1);

			if (ithBit == 0) {//ith bit of n is 0.

				if (current->left == NULL) {
					current->left = new Node();
				}

				current = current->left;

			} else {//ith bit of n is 1.

				if (current->right == NULL) {
					current->right = new Node();
				}

				current = current->right;
			}
		}
	}

	bool Search(int n) {
		Node* current = root;
		for (int i = 31; i >= 0; i--) {
			int ithBit = ((n >> i) & 1);

			if (ithBit == 0) {//ith bit of n is 0.

				if (current->left == NULL) {
					return false;
				}
				current = current->left;

			} else {//ith bit of n is 1.

				if (current->right == NULL) {
					return false;
				}
				current = current->right;
			}
		}
		return true;
	}
};

int main() {
	int a[] {2, 4, 8, 12, 17, 19};
	Trie t;

	for (auto x : a) {
		t.Insert(x);
	}
	int b[] {2, 4, 5, 7, 9, 19, 17};

	for (int i = 0; i < 7; i++) {

		if (t.Search(b[i]) == 1) {
			cout << "Present" << endl;
		} else {
			cout << "Absent" << endl;
		}
	}
}