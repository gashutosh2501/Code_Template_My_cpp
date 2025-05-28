#include<iostream>
#include<vector>
using  namespace std;
int n, m;
vector<int>gr[100001];
vector<int>rev_gr[10001];
vector<int>order;


void dfs(int node, bool *visited) {
	visited[node] = 1;

	for (int child : gr[node]) {
		if (!visited[child]) {
			dfs(child, visited);
		}
	}

	order.push_back(node);
}

void dfs_reverse(int node, bool *visited) {
	visited[node] = 1;
	cout << node << " ";
	for (int child : gr[node]) {
		if (!visited[child]) {
			dfs_reverse(child, visited);
		}
	}
}

void Kosaraju() {
	//Dfs Call on the normal graph and maintain the order vector.
	bool visited[100001] {0};
	bool reverse_visited[100001] {0};

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i, visited);
		}
	}


	//We Already have the reverse graph.
	int component = 1;

	for (int i = order.size() - 1; i >= 0; i--) {
		if (reverse_visited[order[i]] == 0) {
			dfs_reverse(order[i], reverse_visited);
			cout << endl;
			component++;
		}
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		rev_gr[y].push_back(x);
	}

	Kosaraju();

}