#include<iostream>
#include<vector>
using  namespace std;
vector<int>lps;

void SolveLPS(string &s, vector<int>&lps) {
	/*
		ans stores the longest length of
		prefix which is also suffix for the
		previous index.
	*/
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

	/*
		It is going to store the indexes of the
		matched pattern.
	*/
	vector<int>ans;

	int i = 0;//For Traversing over ostr.
	int j = 0;//For Traversing over p;

	while (i < n) {

		//If my ostr[i]==p[j] then
		//character matches and just do
		//i++,j++;

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

	// string ostr = "abcdaabceaabceaabdop";
	// string pat = "aabceaabdo";

	int t;
	cin >> t;
	while (t--) {
		string pat, ostr;
		cin >> ostr >> pat;
		lps.resize(pat.length(), 0);

		SolveLPS(pat, lps);
		// for (auto x : lps) {
		// 	cout << x << " ";
		// }
		// cout << endl;
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

	/*
		a a b c e a a b d o
		0 1 0 0 0 1 2 3 0 0
	*/





}