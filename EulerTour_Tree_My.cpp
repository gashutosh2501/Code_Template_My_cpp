#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200005;
vector<int> tree[N];
vector<int> value;
vector<int> start_time, end_time, lt;
int timer = 1;

class SegmentTree {
public:
    vector<int> tree;
    int n;
    function<int(int, int)> combine;
    int defaultValue;

    SegmentTree(vector<int>& a, function<int(int, int)> _combine, int _defaultValue) {
        n = a.size() - 1;  // 1-based indexing
        tree.resize(4 * n + 1);
        combine = _combine;
        defaultValue = _defaultValue;
        build(a, 1, n, 1);
    }

    void build(vector<int>& a, int ss, int se, int index) {
        if (ss == se) {
            tree[index] = a[ss];
            return;
        }
        int mid = (ss + se) / 2;
        build(a, ss, mid, 2 * index);
        build(a, mid + 1, se, 2 * index + 1);
        tree[index] = combine(tree[2 * index], tree[2 * index + 1]);
    }

    void update(int ss, int se, int i, int val, int index) {
        if (i < ss || i > se) return;
        if (ss == se) {
            tree[index] = val;
            return;
        }
        int mid = (ss + se) / 2;
        update(ss, mid, i, val, 2 * index);
        update(mid + 1, se, i, val, 2 * index + 1);
        tree[index] = combine(tree[2 * index], tree[2 * index + 1]);
    }

    int query(int ss, int se, int qs, int qe, int index) {
        if (qe < ss || qs > se) return defaultValue;
        if (ss >= qs && se <= qe) return tree[index];
        int mid = (ss + se) / 2;
        int left = query(ss, mid, qs, qe, 2 * index);
        int right = query(mid + 1, se, qs, qe, 2 * index + 1);
        return combine(left, right);
    }
};

//Sample Euler Tour with duplicate on Tree 
//*********************************************************************************************************************************************************************
void euler_tour(int node, int par) {
    start_time[node] = timer;
    lt[timer] = value[node];
    timer++;

    for (auto child : tree[node]) {
        if (child != par)
            euler_tour(child, node);
    }

    end_time[node] = timer;
    lt[timer] = value[node];
    timer++;
}
//*********************************************************************************************************************************************************************

int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    start_time.resize(n + 1);
    end_time.resize(n + 1);
    lt.resize(2 * n + 2); // since 1-based indexing and 2 entries per node
    value.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    euler_tour(1, 0);

    SegmentTree seg(lt, [](int a, int b) { return a + b; }, 0);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s, x;
            cin >> s >> x;
            seg.update(1, 2 * n + 1, start_time[s], x, 1);
            seg.update(1, 2 * n + 1, end_time[s], x, 1);
            value[s] = x;
        } else {
            int s;
            cin >> s;
            int result = seg.query(1, 2 * n + 1, start_time[s], end_time[s], 1);
            cout << (result / 2) << '\n';
        }
    }

    return 0;
}
