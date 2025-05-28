#include<iostream>
#include<unordered_map>
using  namespace std;

//This is treated as my own data type.
class Node {
public:
	char ch;
	bool terminal;
	unordered_map<char, Node*>childMap;
	int freq;

	//Parameterised Constructor
	Node(char ch) {
		this->ch = ch;
		this->terminal = false;
		this->freq = 0;
	}
};


class Trie {
private:
	Node* root;
	int n = 0;
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
			current->freq++;
		}
		current->terminal = true;
		n++;
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

	//O(length of String)

	string ShortestUniquePrefix(string &str) {
		Node* current = root;
		string ans = "";

		for (char ch : str) {
			ans += ch;
			current = current->childMap[ch];

			if (current->freq == 1) {
				return ans;
			}

		}
		return "";//Str doesn't have any
		//unique Prefix.
	}


	string LongestCommonPrefix(string &str) {
		cout << n << endl;
		Node* current = root;
		string ans = "";

		for (char ch : str) {
			current = current->childMap[ch];
			if (current->freq != n) {
				break;
			}
			ans += ch;

		}
		return ans;
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

	// int q;
	// cin >> q;

	// while (q--) {

	// 	string st;
	// 	cin >> st;

	// 	cout << t.Search(st) << endl;
	// }

	// int q1;
	// cin >> q1;

	// while (q1--) {
	// 	string str;
	// 	cin >> str;

	// 	cout << t.ShortestUniquePrefix(str) << endl;
	// }
	cout << t.LongestCommonPrefix(s[0]) << endl;
}
















