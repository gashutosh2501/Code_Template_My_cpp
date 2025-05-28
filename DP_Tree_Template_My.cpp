/*************************************************
    Tree DP – farthest-node distance for each node
    author: Ashutosh-style template
 *************************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200000 + 5;        // 2e5 + safety
vector<int> tree[N];
int depth[N];                    // max depth inside the subtree
int ans[N];                      // required answer for every node

/************* 1st DFS – get subtree depths *************/
void dfs_depth(int u, int p)
{
    depth[u] = 0;                // leaf ⇒ depth 0
    for (int v : tree[u])
        if (v != p)
        {
            dfs_depth(v, u);
            depth[u] = max(depth[u], 1 + depth[v]);
        }
}

/************* 2nd DFS – rerooting DP *************/
void solve(int u, int p, int up_contrib)
/* up_contrib = best distance that reaches u *through its parent* */
{
    /* gather depths of all children (excluding parent) */
    vector<int> childDep;
    for (int v : tree[u])
        if (v != p) childDep.push_back(depth[v]);

    /* prefix / suffix maxima of those depths */
    int m = childDep.size();
    vector<int> pref(m), suff(m);
    for (int i = 0; i < m; ++i)
        pref[i] = (i ? max(pref[i - 1], childDep[i]) : childDep[i]);
    for (int i = m - 1; i >= 0; --i)
        suff[i] = (i + 1 < m ? max(suff[i + 1], childDep[i]) : childDep[i]);

    /* answer for u itself */
       // 1 accounts for edge to that child/parent

    /* propagate to children */
    int idx = 0;
    for (int v : tree[u])
    {
        //cout<<"YO+"<<v<<" "<<u<<"-YO"<<endl; for debug
        if (v == p) continue;

        

        int left  = (idx ? pref[idx - 1] : -1);
        int right = (idx + 1 < m ? suff[idx + 1] : -1);
        int pass  = 1 + max(up_contrib, max(left, right));
        solve(v, u, pass);

        ++idx;
    }
    int best_down = (m ? pref.back() : -1);      // best depth among its children
    ans[u] = 1 + max(up_contrib, best_down); 
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;                 // number of nodes
    if (!(cin >> n)) return 0;

    for (int i = 1; i <= n; ++i) tree[i].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v;
        tree[u].push_back(v);
        //tree[v].push_back(u);
    }

    dfs_depth(1, 0);          // root the first DFS at 1
    solve(1, 0, -1);     // second DFS, parent contribution = -1 (none)

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
