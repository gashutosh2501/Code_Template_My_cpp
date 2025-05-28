#include<iostream>
#include<climits>
using  namespace std;


void BuildTree(int *a, int s, int e, int *tree, int index) {

	//Base Condition
	if (s == e) {
		tree[index] = a[s];
		return;
	}

	//Recursive Condtion:

	int mid = (s + e) / 2;
	BuildTree(a, s, mid, tree, 2 * index);
	BuildTree(a, mid + 1, e, tree, 2 * index + 1);

	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;
}


int Query(int *tree, int ss, int se, int qs, int qe, int index) {

	//Complete Overlap
	if (ss >= qs and se <= qe) {
		return tree[index];
	}

	//No Overlap:
	if (qe<ss or qs>se) {
		return INT_MAX;
	}


	//Partial Overlap

	int mid = (ss + se) / 2;
	int left = Query(tree, ss, mid, qs, qe, 2 * index);
	int right = Query(tree, mid + 1, se, qs, qe, 2 * index + 1);

	return min(left, right);
}


void Update(int *tree, int ss, int se, int i, int increment, int index) {

	//Case where the i is out of bounds.
	if (i > se or i < ss) {
		return;
	}


	//leaf Node:
	if (ss == se) {
		tree[index] = increment;
		return;
	}

	//Otherwise
	int mid = (ss + se) / 2;
	Update(tree, ss, mid, i, increment, 2 * index);
	Update(tree, mid + 1, se, i, increment, 2 * index + 1);

	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;
}

void UpdateRange(int *tree, int ss, int se, int l, int r, int inc, int index) {

	//Out of Bounds
	if (l > se or r < ss) {
		return;
	}

	//Leaf Node
	if (ss == se) {
		tree[index] += inc;
		return;
	}

	//Otherwise
	int mid = (ss + se) / 2;
	UpdateRange(tree, ss, mid, l, r, inc, 2 * index);
	UpdateRange(tree, mid + 1, se, l, r, inc, 2 * index + 1);

	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;
}

int lazy[100001] {0};

void UpdateRangeLazy(int *tree, int ss, int se, int l, int r, int inc, int index) {

	//Before Going Down Reolve the lazy value if it exists.
	if (lazy[index] != 0) {
		tree[index] += lazy[index];

		//Non leaf node
		if (ss != se) {
			lazy[2 * index] += lazy[index];
			lazy[2 * index + 1] += lazy[index];
		}

		lazy[index] = 0;
	}


	//Base Condtion
	//No Overlap
	if (ss > r or l > se) {
		return;
	}

	//Complete Overlap
	if (ss >= l and se <= r) {
		tree[index] += inc;

		//Update children's lazy value by inc.
		if (ss != se) {
			lazy[2 * index] += inc;
			lazy[2 * index + 1] += inc;
		}
		return;
	}


	//Partial Overlap
	//Recursive Case:

	int mid = (ss + se) / 2;
	UpdateRangeLazy(tree, ss, mid, l, r, inc, 2 * index);
	UpdateRangeLazy(tree, mid + 1, se, l, r, inc, 2 * index + 1);

	//Update the rest of value;
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;
}


int QueryLazy(int *tree, int ss, int se, int l, int r, int index) {

	//Resolve the lazy Values;
	//Before Going Down Reolve the lazy value if it exists.
	if (lazy[index] != 0) {
		tree[index] += lazy[index];

		//Non leaf node
		if (ss != se) {
			lazy[2 * index] += lazy[index];
			lazy[2 * index + 1] += lazy[index];
		}

		lazy[index] = 0;
	}


	//Base Condtion
	//No Overlap
	if (ss > r or l > se) {
		return INT_MAX;
	}

	//Complete Overlap
	if (ss >= l and se <= r) {
		return tree[index];
	}

	//Partial Overlap
	//Recursive Case:

	int mid = (ss + se) / 2;
	int left = QueryLazy(tree, ss, mid, l, r, 2 * index);
	int right = QueryLazy(tree, mid + 1, se, l, r, 2 * index + 1);

	return min(left, right);
}


int main() {

	int a[] {5, 2, 7, 1, 3, 9};
	int n = sizeof(a) / sizeof(int);
	int *tree = new int[4 * n + 1];
	BuildTree(a, 0, n - 1, tree, 1);

	int q;
	cin >> q;

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << Query(tree, 0, n - 1, l, r, 1) << endl;
	}

}
