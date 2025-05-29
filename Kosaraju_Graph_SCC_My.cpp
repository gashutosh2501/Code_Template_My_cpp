#include <bits/stdc++.h>
#define int long long
using namespace std;

// Graph and its transpose (reverse edges)
vector<vector<int>> adj;      // Normal directed graph
vector<vector<int>> adjT;     // Transposed graph (all edges reversed)

vector<bool> visited;         // visited[] for the first DFS
vector<bool> visitedT;        // visitedT[] for the second DFS on transpose
stack<int> stack1;            // stack to store finish order
int count_scc = 0;            // counter to store number of Strongly Connected Components
vector<int> result;

// For finding Strongly Connected Components (SCCs) in a directed graph.
// SCC means each node in the component can reach every other node in the same component.

// First DFS to visit nodes and push them onto stack in postorder (finishing time order)
void dfs(int src) {
    visited[src] = true;
    for (auto child : adj[src]) {
        if (!visited[child]) {
            dfs(child);
        }
    }
    stack1.push(src);  // push after visiting all children (postorder)
}

// Second DFS on the transposed graph to visit one entire SCC
void dfs3(int src) {
    visitedT[src] = true;
    for (auto child : adjT[src]) {
        if (!visitedT[child]) {
            dfs3(child);
        }
    }
}

// Apply Kosaraju's algorithm to count the number of SCCs
void kosaraju() {
    while (!stack1.empty()) {
        int node = stack1.top();
        stack1.pop();
        if (!visitedT[node]) {
            count_scc++;     // new SCC found
            result.push_back(node);// Save representative(head/start) of this SCC
            
            dfs3(node);      // visit all nodes in this SCC in the transpose graph

        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // Resize graph containers to hold n nodes (1-based indexing)
    adj.resize(n + 1);
    adjT.resize(n + 1);
    visited.assign(n + 1, false);
    visitedT.assign(n + 1, false);
    

    // Build graph and its transpose
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);     // original edge
        adjT[b].push_back(a);    // reversed edge for transpose
    }

    // Run DFS for all unvisited nodes (handles disconnected components)
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Run Kosaraju to count SCCs
    kosaraju();

    // Output the number of strongly connected components
    if(count_scc>1)
    {
        cout<<"NO"<<endl;
        cout<<result[1]<<" "<<result[0]<< endl;


    }
    else
    {
        cout<<"YES"<<endl;
    }
    
   

    return 0;
}
