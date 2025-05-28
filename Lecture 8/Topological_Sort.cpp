#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<algorithm>
#include<climits>
using  namespace std;


template<typename T>
class Graph {
	map<T, list<T>>mp;//Adj. List
	map<T, int>visited;
public:

	void AddEdge(T x, T y) {
		mp[x].push_back(y);
	}

	void bfs() {

		map<T, int>indegree;
		for (auto x : mp) {
			indegree[x.first] = 0;
		}

		for (auto x : mp) {
			for (auto y : x.second) {
				indegree[y]++;
			}
		}


		queue<T>q;

		for (auto x : indegree) {
			if (x.second == 0) {
				q.push(x.first);
			}
		}

		while (!q.empty()) {

			T node = q.front();
			q.pop();

			cout << node << " ";

			for (auto nbr : mp[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}
	}

	void dfs_helper(T node, list<int>&order) {
		visited[node] = 1;

		for (T nbr : mp[node]) {
			if (visited[nbr] == 0) {
				dfs_helper(nbr, order);
			}
		}
		order.push_front(node);
	}

	void dfs() {
		//By default map me every key is initialised with 0.

		list<int>order;
		for (auto x : mp) {
			T node = x.first;
			visited[node] = 0;
		}

		for (auto x : mp) {
			T node = x.first;
			if (!visited[node]) {
				dfs_helper(node, order);
			}
		}


		for (auto x : order) {
			cout << x << " ";
		}

		cout << endl;
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	Graph<int>gr;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr.AddEdge(x, y);
	}
	gr.dfs();
	cout << "--------" << endl;
	gr.bfs();

}











