#include<iostream>
#include<string>
#include<cstring>
using  namespace std;

string  s, t;
int dp[3001][3001];
//Computations: ~(3000*3000*3+3001)
//Space: 3001*3001

//Solve(0,98);0

int lenLCS(int i, int j) {

	if (i >= s.length() or j >= t.length()) {
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}


	int Op1 = 0, Op2 = 0;

	if (s[i] == t[j]) {
		return dp[i][j] = 1 + lenLCS(i + 1, j + 1);
	} else {

		Op1 = 0 + lenLCS(i + 1, j);
		Op2 = 0 + lenLCS(i, j + 1);

		return dp[i][j] = max(Op1, Op2);
	}
}

string PrintLCS(int i, int j, int LCS) {

	string ans = "";

	while (LCS > 0) {

		if (s[i] == t[j]) {
			ans.push_back(s[i]);
			LCS--;
			i++;
			j++;
		} else {

			//s[i]!=t[j]

			if (dp[i + 1][j] > dp[i][j + 1]) {
				i++;
			} else {
				j++;
			}

		}
	}

	return ans;
}


string getLCS(int i, int j) {
	memset(dp, -1, sizeof(dp));

	int length = lenLCS(0, 0);

	return PrintLCS(0, 0, length);
}




int main() {
	cin >> s >> t;
	cout << getLCS(0, 0) << endl;
}





