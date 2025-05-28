/*
	Implemention of the Trie DS to store strings.

	Motivation:

	Given an Array of N strings,and an array of
	q queries check for each query if it is present
	in the array or not.

*/

#include<iostream>
#include<unordered_map>
using  namespace std;

//This is treated as my own data type.
class Node {
public:
	char ch;
	bool terminal;
	unordered_map<char, Node*>childMap;

	//Parameterised Constructor
	Node(char ch) {
		this->ch = ch;
		this->terminal = false;
	}
};


class Trie {
private:
	Node* root;
public:
	Trie() {
		root = new Node('\0');
	}

	/*
		Everything is going to happen in
		O(length of strring/Word).
	*/

	void Insert(string &str) {
		Node* current = root;

		for (char ch : str) {
			if (current->childMap.find(ch) ==
			        current->childMap.end()) {

				//I don't have the current
				//character in my hashmap.

				Node* n = new Node(ch);
				current->childMap[ch] = n;
			}
			current = current->childMap[ch];
		}
		current->terminal = true;
	}

	bool Search(string &str) {

		Node* current = root;
		for (char ch : str) {
			if (current->childMap.count(ch) == 0) {
				return false;
			}
			current = current->childMap[ch];
		}

		return current->terminal;
	}



};



int main() {

	// Node Mayank1('z');

	// Node * mayank = new Node('z');
	// delete mayank;

	int n;
	cin >> n;
	string s[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	Trie t;

	for (string word : s) {
		t.Insert(word);
	}

	int q;
	cin >> q;

	while (q--) {

		string st;
		cin >> st;

		cout << t.Search(st) << endl;
	}
}


