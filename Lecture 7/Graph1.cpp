#include<iostream>
#include<list>
#include<map>
#include<queue>
using  namespace std;


template<typename T>
class Graph {
	map<T, list<T>>mp;//Adj. List
	map<T, bool>visited;
public:

	void AddEdge(T x, T y) {
		mp[x].push_back(y);
		mp[y].push_back(x);
	}

	void bfs(T scr) {

		queue<T>q;
		q.push(scr);
		visited[scr] = 1;

		while (!q.empty()) {

			T node = q.front();
			q.pop();

			cout << node << " ";

			for (T nbr : mp[node]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = 1;
				}
			}
		}
	}

	void dfs_helper(T scr) {
		cout << scr << " ";
		visited[scr] = 1;

		for (T nbr : mp[scr]) {
			if (!visited[nbr]) {
				dfs_helper(nbr);
			}
		}
	}

	void dfs(int scr) {
		visited.clear();
		dfs_helper(scr);
	}

	void Print() {
		for (pair<T, list<T>> x : mp) {
			cout << x.first << ":  ";
			for (T y : x.second) {
				cout << y << " ";
			}
			cout << endl;
		}
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

	gr.Print();
	// gr.bfs(1);
	// cout << endl;
	// gr.dfs(1);


}