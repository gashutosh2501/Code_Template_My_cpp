#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200005;
vector<int> tree[N];
vector<int> value_node;
vector<int> heavy, depth, parent, size1;
vector<int> lt, head, pos;
int idx;

class SegmentTree {
public:
    vector<int> tree;
    int n;
    function<int(int, int)> combine;
    int defaultValue;

    SegmentTree(vector<int> &a, function<int(int, int)> _combine, int _defaultValue) {
        n = a.size() - 1;
        tree.resize(4 * n + 1);
        combine = _combine;
        defaultValue = _defaultValue;
        BuildTree(a, 1, n, 1);
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
        if (qe < ss || qs > se) return defaultValue;
        if (ss >= qs && se <= qe) return tree[index];
        int mid = (ss + se) / 2;
        int left = Query(ss, mid, qs, qe, 2 * index);
        int right = Query(mid + 1, se, qs, qe, 2 * index + 1);
        return combine(left, right);
    }

    void Update(int ss, int se, int i, int val, int index) {
        if (i < ss || i > se) return;
        if (ss == se) {
            tree[index] = val;
            return;
        }
        int mid = (ss + se) / 2;
        Update(ss, mid, i, val, 2 * index);
        Update(mid + 1, se, i, val, 2 * index + 1);
        tree[index] = combine(tree[2 * index], tree[2 * index + 1]);
    }
};

void dfs(int src, int par) {
    parent[src] = par;
    size1[src] = 1;
    int max_size = 0;
    for (auto child : tree[src]) {
        if (child == par) continue;
        depth[child] = depth[src] + 1;
        dfs(child, src);
        size1[src] += size1[child];
        if (size1[child] > max_size) {
            max_size = size1[child];
            heavy[src] = child;
        }
    }
}

void hld(int src, int chain) {
    head[src] = chain;
    pos[src] = idx;
    lt[idx] = value_node[src];
    idx++;
    if (heavy[src] != -1) hld(heavy[src], chain);
    for (auto child : tree[src]) {
        if (child != parent[src] && child != heavy[src]) {
            hld(child, child);
        }
    }
}

int solve_hld(int a, int b, SegmentTree &seg) {
    int sum = 0;
    while (head[a] != head[b]) {
        if (depth[head[a]] < depth[head[b]]) swap(a, b);
        sum += seg.Query(1, idx - 1, pos[head[a]], pos[a], 1);
        a = parent[head[a]];
    }
    if (depth[a] > depth[b]) swap(a, b);
    sum += seg.Query(1, idx - 1, pos[a], pos[b], 1);
    return sum;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    heavy.assign(n + 1, -1);
    depth.resize(n + 1);
    head.resize(n + 1);
    value_node.resize(n + 1);
    size1.resize(n + 1);
    parent.resize(n + 1);
    pos.resize(n + 1);
    lt.resize(n + 1);
    idx = 1;

    for (int i = 1; i <= n; i++) {
        cin >> value_node[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0);
    hld(1, 1);

    SegmentTree seg(lt, [](int x, int y) { return x + y; }, 0);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s, x;
            cin >> s >> x;
            seg.Update(1, idx - 1, pos[s], x, 1);
            value_node[s] = x;
        } else {
            int s;
            cin >> s;
            cout << solve_hld(s, 1, seg) << '\n';
        }
    }

    return 0;
}
