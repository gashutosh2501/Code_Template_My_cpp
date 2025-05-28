#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;
vector<int>gr[200001];

int diameter[200001];
int downpath[200001];

void Solve(int node, int parent) {

	bool leaf = 1;//Assume Current node is the leaf node.
	int ans = 0;//This variable stores the maximum downpath
	//from a subtree.


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

	int ans = 0;//This will help me in calculating max values.
	vector<int>childdownpaths;

	//The Above vector will store all the downpaths of the
	//child node of the current node which will
	//help us in op1 calculation where for finding
	///out the  diameter of the current node we
	//need the maximum 2 downpaths of the child node.

	for (auto child : gr[node]) {
		if (child != parent) {
			Solve(child, node);
			childdownpaths.push_back(downpath[child]);

			//Op2:Diameter does not pass through root node.
			ans = max(ans, diameter[child]);
		}
	}


	//Diameter Calculation.
	int Noofchild = childdownpaths.size();

	//I am Sorting because for the current
	// node I need maximum 2 downpath vvaale child.
	//Des. Order me sort karna hain
	sort(childdownpaths.rbegin(), childdownpaths.rend());
	//sort(childdownpaths.begin(), childdownpaths.end(), greater<int>());

	if (Noofchild == 0) {
		//This is a Leaf node
		diameter[node] = 0;
	} else if (Noofchild == 1) {
		diameter[node] = 1 + childdownpaths[0];
	} else {
		diameter[node] = 2 + childdownpaths[0] + childdownpaths[1];
	}



	//Abhi diameter[node] me op1 ke karan diameter
	//store hain.

	//final diameter
	diameter[node] = max(ans, diameter[node]);
	return;
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

	Solve(1, 0);//This is to calculate the downpaths from every node
	Calculate(1, 0); //Main Diamter finding Logic.

	cout << diameter[1] << endl;

}