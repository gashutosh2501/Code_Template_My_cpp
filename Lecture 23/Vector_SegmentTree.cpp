#include<iostream>
#include<climits>
#include<vector>
using namespace std;

vector<int> lazy(100001, 0);

void BuildTree(vector<int> &a, int s, int e, vector<int> &tree, int index) {
	if (s == e) {
		tree[index] = a[s];
		return;
	}

	int mid = (s + e) / 2;
	BuildTree(a, s, mid, tree, 2 * index);
	BuildTree(a, mid + 1, e, tree, 2 * index + 1);

	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

int Query(vector<int> &tree, int ss, int se, int qs, int qe, int index) {
	if (ss >= qs && se <= qe) return tree[index];
	if (qe < ss || qs > se) return INT_MAX;

	int mid = (ss + se) / 2;
	int left = Query(tree, ss, mid, qs, qe, 2 * index);
	int right = Query(tree, mid + 1, se, qs, qe, 2 * index + 1);

	return min(left, right);
}

void Update(vector<int> &tree, int ss, int se, int i, int increment, int index) {
	if (i < ss || i > se) return;

	if (ss == se) {
		tree[index] = increment;
		return;
	}

	int mid = (ss + se) / 2;
	Update(tree, ss, mid, i, increment, 2 * index);
	Update(tree, mid + 1, se, i, increment, 2 * index + 1);

	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

void UpdateRange(vector<int> &tree, int ss, int se, int l, int r, int inc, int index) {
	if (r < ss || l > se) return;

	if (ss == se) {
		tree[index] += inc;
		return;
	}

	int mid = (ss + se) / 2;
	UpdateRange(tree, ss, mid, l, r, inc, 2 * index);
	UpdateRange(tree, mid + 1, se, l, r, inc, 2 * index + 1);

	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

void UpdateRangeLazy(vector<int> &tree, int ss, int se, int l, int r, int inc, int index) {
	// Resolve pending lazy updates
	if (lazy[index] != 0) {
		tree[index] += lazy[index];
		if (ss != se) {
			lazy[2 * index] += lazy[index];
			lazy[2 * index + 1] += lazy[index];
		}
		lazy[index] = 0;
	}

	// No Overlap
	if (r < ss || l > se) return;

	// Complete Overlap
	if (ss >= l && se <= r) {
		tree[index] += inc;
		if (ss != se) {
			lazy[2 * index] += inc;
			lazy[2 * index + 1] += inc;
		}
		return;
	}

	// Partial Overlap
	int mid = (ss + se) / 2;
	UpdateRangeLazy(tree, ss, mid, l, r, inc, 2 * index);
	UpdateRangeLazy(tree, mid + 1, se, l, r, inc, 2 * index + 1);

	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

int QueryLazy(vector<int> &tree, int ss, int se, int l, int r, int index) {
	// Resolve lazy values
	if (lazy[index] != 0) {
		tree[index] += lazy[index];
		if (ss != se) {
			lazy[2 * index] += lazy[index];
			lazy[2 * index + 1] += lazy[index];
		}
		lazy[index] = 0;
	}

	// No Overlap
	if (r < ss || l > se) return INT_MAX;

	// Complete Overlap
	if (ss >= l && se <= r) return tree[index];

	// Partial Overlap
	int mid = (ss + se) / 2;
	int left = QueryLazy(tree, ss, mid, l, r, 2 * index);
	int right = QueryLazy(tree, mid + 1, se, l, r, 2 * index + 1);

	return min(left, right);
}

int main() 
{
	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
	
	vector<int> a = {5, 2, 7, 1, 3, 9};
	int n = a.size();
	vector<int> tree(4 * n + 1);

	BuildTree(a, 0, n - 1, tree, 1);

	int q;
	cin >> q;

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << Query(tree, 0, n - 1, l, r, 1) << endl;
	}
}
