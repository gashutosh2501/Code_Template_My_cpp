#include<bits/stdc++.h>
#define int long long 
using namespace std;

class SegmentTree {
public:
	vector<int> tree;
	vector<int> lazy;
	int n;
	function<int(int, int)> combine;
	int defaultValue;

	SegmentTree(vector<int> &a, function<int(int, int)> _combine, int _defaultValue) {
		n = a.size();
		tree.resize(4 * n + 1);
		lazy.resize(4 * n + 1, 0);
		combine = _combine;
		defaultValue = _defaultValue;
		BuildTree(a, 1, n , 1);
	}

	void BuildTree(vector<int> &a, int s, int e, int index) {
		if (s == e) {
			tree[index] = a[s];
			return;
		}

		int mid = (s + e) / 2;
		BuildTree(a, s, mid, 2 * index);
		BuildTree(a, mid + 1, e, 2 * index + 1);

		tree[index] = combine(tree[2 * index], tree[2 * index + 1]);
	}

	int Query(int ss, int se, int qs, int qe, int index) {
		if (lazy[index] != 0) {
			tree[index] += lazy[index];
			if (ss != se) {
				lazy[2 * index] += lazy[index];
				lazy[2 * index + 1] += lazy[index];
			}
			lazy[index] = 0;
		}

		// No Overlap
		if (qe < ss || qs > se) return defaultValue;

		// Complete Overlap
		if (ss >= qs && se <= qe) return tree[index];

		// Partial Overlap
		int mid = (ss + se) / 2;
		int left = Query(ss, mid, qs, qe, 2 * index);
		int right = Query(mid + 1, se, qs, qe, 2 * index + 1);

		return combine(left, right);
	}

	void Update(int ss, int se, int i, int increment, int index) {
		if (i < ss || i > se) return;

		if (ss == se) {
			tree[index] = increment;
			return;
		}

		int mid = (ss + se) / 2;
		Update(ss, mid, i, increment, 2 * index);
		Update(mid + 1, se, i, increment, 2 * index + 1);

		tree[index] = combine(tree[2 * index], tree[2 * index + 1]);
	}

	void UpdateRange(int ss, int se, int l, int r, int inc, int index) {
		if (r < ss || l > se) return;

		if (ss == se) {
			tree[index] += inc;
			return;
		}

		int mid = (ss + se) / 2;
		UpdateRange(ss, mid, l, r, inc, 2 * index);
		UpdateRange(mid + 1, se, l, r, inc, 2 * index + 1);

		tree[index] = combine(tree[2 * index], tree[2 * index + 1]);
	}

	void UpdateRangeLazy(int ss, int se, int l, int r, int inc, int index) {
		if (lazy[index] != 0) {
			tree[index] += lazy[index];
			if (ss != se) {
				lazy[2 * index] += lazy[index];
				lazy[2 * index + 1] += lazy[index];
			}
			lazy[index] = 0;
		}

		if (r < ss || l > se) return;

		if (ss >= l && se <= r) {
			tree[index] += inc;
			if (ss != se) {
				lazy[2 * index] += inc;
				lazy[2 * index + 1] += inc;
			}
			return;
		}

		int mid = (ss + se) / 2;
		UpdateRangeLazy(ss, mid, l, r, inc, 2 * index);
		UpdateRangeLazy(mid + 1, se, l, r, inc, 2 * index + 1);

		tree[index] = combine(tree[2 * index], tree[2 * index + 1]);
	}

	int QueryLazy(int ss, int se, int l, int r, int index) {
		if (lazy[index] != 0) {
			tree[index] += lazy[index];
			if (ss != se) {
				lazy[2 * index] += lazy[index];
				lazy[2 * index + 1] += lazy[index];
			}
			lazy[index] = 0;
		}

		if (r < ss || l > se) return defaultValue;

		if (ss >= l && se <= r) return tree[index];

		int mid = (ss + se) / 2;
		int left = QueryLazy(ss, mid, l, r, 2 * index);
		int right = QueryLazy(mid + 1, se, l, r, 2 * index + 1);

		return combine(left, right);
	}
};

int32_t main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> a = {5, 2, 7, 1, 3, 9};
	int n = a.size();

	// Create Segment Tree (for min query)
	SegmentTree st(a, [](int a, int b) { return min(a, b); }, INT_MAX);

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << st.Query(0, n - 1, l, r, 1) << endl;
	}
}
