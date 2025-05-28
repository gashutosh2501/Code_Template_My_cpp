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
		mp[y].push_back(x);
	}



	bool dfs_helper(T node, T parent, int color) {
		visited[node] = color;

		for (T nbr : mp[node]) {
			if (visited[nbr] == 0) {
				bool small_ans = dfs_helper(nbr, node, 3 - color);
				if (small_ans == 0) {
					return false;
				}
			} else if (nbr != parent and visited[nbr] == color) {
				return false;
			}
		}
		return true;
	}

	bool dfs(int scr) {
		//By default map me every key is initialised with 0.

		for (pair < T, list<T>> x : mp) {
			visited[x.first] = 0;
		}

		int color = 1;
		return dfs_helper(1, -1, color);
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
	gr.dfs(1);

}











