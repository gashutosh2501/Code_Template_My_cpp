#include<iostream>
using  namespace std;

class Solution {
	int solve(int index1, int index2, string &word1, string &word2, vector<vector<int>> &dp) {
		if (index1 < 0) {
			return index2 + 1;
		}
		if (index2 < 0) {
			return index1 + 1;
		}
		if (dp[index1][index2] != -1) {
			return dp[index1][index2];
		}
		if (word1[index1] == word2[index2]) {
			return 0 + solve(index1 - 1, index2 - 1, word1, word2, dp);
		}
		int insertion = 1 + solve(index1, index2 - 1, word1, word2, dp);
		int deletion = 1 + solve(index1 - 1, index2, word1, word2, dp);
		int replacement = 1 + solve(index1 - 1, index2 - 1, word1, word2, dp);
		return dp[index1][index2] = min(insertion, min(deletion, replacement));
	}
public:
	int minDistance(string word1, string word2) {
		int n1 = word1.size();
		int n2 = word2.size();
		vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
		return solve(n1 - 1, n2 - 1, word1, word2, dp);
	}
};

class Solution2 {
public:
	int minDistance(string word1, string word2) {
		const int m = word1.length();//first word length
		const int n = word2.length();//second word length
		// dp[i][j] := min # of operations to convert word1[0..i) to word2[0..j)
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));

		for (int i = 1; i <= m; ++i)
			dp[i][0] = i;

		for (int j = 1; j <= n; ++j)
			dp[0][j] = j;

		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				if (word1[i - 1] == word2[j - 1])//same characters
					dp[i][j] = dp[i - 1][j - 1];//no operation
				else
					dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
		//replace       //delete        //insert
		return dp[m][n];
	}
};

int main() {

}