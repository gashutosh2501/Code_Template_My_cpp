#include<iostream>
#include<vector>
using  namespace std;
vector<int>gr[200001];

void Solve(int node, int parent, vector<int>&dp) {

	//Current Subtree which is rooted at node uske abtak
	//ke subordinates kitne hain.
	int Subordinates = 0;

	for (auto child : gr[node]) {
		if (child != parent) {
			Solve(child, node, dp);

			//When you are here.
			Subordinates += 1 + dp[child];
		}
	}

	//Now you have the subordinates of node.

	dp[node] = Subordinates;
	return;
}



int main() {
	int n;
	cin >> n;
	vector<int>dp(n + 1);//I will be taking 1 based indexing

	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		gr[x].push_back(i);
		gr[i].push_back(x);
	}

	Solve(1, 0, dp);

	for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}
}





