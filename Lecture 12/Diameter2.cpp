#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;
vector<int>gr[200001];

int diameter[200001];
int downpath[200001];

void Solve(int node, int parent) {

	bool leaf = 1;
	int ans = 0;

	for (auto child : gr[node]) {
		if (child != parent) {
			leaf = 0;
			Solve(child, node);

			//When you are here.
			ans = max(ans, downpath[child]);
		}
	}

	if (leaf == 1) {
		downpath[node] = 0;
	} else {
		downpath[node] = 1 + ans;
	}

	return;
}

void Calculate(int node, int parent) {

	int ans = 0;
	vector<int>childdownpaths;

	for (auto child : gr[node]) {
		if (child != parent) {
			Calculate(child, node);
			childdownpaths.push_back(downpath[child]);
			ans = max(ans, diameter[child]);
		}
	}

	int Noofchild = childdownpaths.size();

	sort(childdownpaths.rbegin(), childdownpaths.rend());

	if (Noofchild == 0) {
		diameter[node] = 0;
	} else if (Noofchild == 1) {
		diameter[node] = 1 + childdownpaths[0];
	} else {
		diameter[node] = 2 + childdownpaths[0] + childdownpaths[1];
	}

	diameter[node] = max(ans, diameter[node]);
}


int main() {

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	Solve(1, 0);
	Calculate(1, 0);

	cout << diameter[1] << endl;

}