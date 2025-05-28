#include<iostream>
#include<vector>
using  namespace std;
vector<int>lps;


// Time Complexity: O(n+m)

void SolveLPS(string &s, vector<int>&lps) {
	int pre = 0;
	lps[0] = 0;
	int suff = 1;
	while (suff < s.length()) {
		if (s[suff] == s[pre]) {
			pre++;
			lps[suff] = pre;
			suff++;
		} else {
			if (pre != 0) {
				pre = lps[pre - 1];
			} else {
				lps[suff] = 0;
				suff++;
			}
		}
	}
}

vector<int>Search(string &p, string &ostr) {
	int n = ostr.length();
	int m = p.length();
	vector<int>ans;

	int i = 0;//For Traversing over ostr.
	int j = 0;//For Traversing over p;

	while (i < n) {
		if (ostr[i] == p[j]) {
			i++;
			j++;
			if (j == m) {
				ans.push_back(i - j);
				//To avoid repeatitions:
				j = lps[j - 1];
			}

		} else {
			//There was a mismatch
			if (j != 0) {
				j = lps[j - 1];
			} else {
				i++;
			}
		}
	}
	return ans;

}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string pat, ostr;
		cin >> ostr >> pat;
		lps.resize(pat.length(), 0);
		SolveLPS(pat, lps);

		vector<int>ans = Search(pat, ostr);
		if (ans.size() == 0) {
			cout << "Not Found";
		} else {
			cout << ans.size() << endl;
		}

		for (auto x : ans) {
			cout << x + 1 << " ";
		}
		cout << endl;
	}
}


//Egg Drop: