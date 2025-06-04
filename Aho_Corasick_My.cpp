#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> child;
    Node* suffix_link;
    Node* output_link;
    int pattern_ind;

    Node() {
        suffix_link = nullptr;
        output_link = nullptr;
        pattern_ind = -1;
    }
};

class AhoCorasick {
public:
    Node* root;

    AhoCorasick() {
        root = new Node();
    }

    void build_trie(const vector<string>& patterns) {
        for (int i = 0; i < patterns.size(); i++) {
            Node* curr = root;
            for (char c : patterns[i]) {
                if (!curr->child.count(c)) {
                    curr->child[c] = new Node();
                }
                curr = curr->child[c];
            }
            curr->pattern_ind = i;
        }
    }

    void build_suffix_and_output_links() {
        queue<Node*> q;
        root->suffix_link = root;

        for (auto& [c, node] : root->child) {
            node->suffix_link = root;
            q.push(node);
        }

        while (!q.empty()) {
            Node* curr = q.front(); q.pop();

            for (auto& [c, childNode] : curr->child) {
                Node* temp = curr->suffix_link;
                while (temp != root && !temp->child.count(c)) {
                    temp = temp->suffix_link;
                }
                if (temp->child.count(c) && temp->child[c] != childNode) {
                    childNode->suffix_link = temp->child[c];
                } else {
                    childNode->suffix_link = root;
                }

                // Output link logic
                if (childNode->suffix_link->pattern_ind != -1) {
                    childNode->output_link = childNode->suffix_link;
                } else {
                    childNode->output_link = childNode->suffix_link->output_link;
                }

                q.push(childNode);
            }
        }
    }

    void search(const string& text, vector<vector<int>>& res) {
        Node* curr = root;

        for (int i = 0; i < text.size(); i++) {
            char c = text[i];

            while (curr != root && !curr->child.count(c)) {
                curr = curr->suffix_link;
            }

            if (curr->child.count(c)) {
                curr = curr->child[c];
            }

            Node* temp = curr;
            while (temp != nullptr) {
                if (temp->pattern_ind != -1) {
                    res[temp->pattern_ind].push_back(i);
                }
                temp = temp->output_link;
            }
        }
    }
};
/////// below main is just and exmample and for reference 

int main() {
    AhoCorasick ac;
    vector<string> patterns = {"he", "she", "his", "hers"};
    string text = "ahishers";

    ac.build_trie(patterns);
    ac.build_suffix_and_output_links();

    vector<vector<int>> res(patterns.size());
    ac.search(text, res);

    for (int i = 0; i < patterns.size(); i++) {
        cout << "Pattern \"" << patterns[i] << "\" found at indices: ";
        for (int ind : res[i]) cout << ind << " ";
        cout << "\n";
    }
}
