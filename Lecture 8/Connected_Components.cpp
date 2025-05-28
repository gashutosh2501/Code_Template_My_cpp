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
	map<T, bool>visited;
public:

	void AddEdge(T x, T y) {
		mp[x].push_back(y);
		mp[y].push_back(x);
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
		//By default map me every key is initialised with 0.

		for (pair < T, list<T>> x : mp) {
			visited[x.first] = 0;
		}

		int cnt = 1;
		for (auto x : mp) {
			if (visited[x.first] == 0) {
				cout << "Component No : " << cnt << " --> ";
				dfs_helper(x.first);
				cnt++;
				cout << endl;
			}
		}

		cout << endl << "Total Components : " << cnt - 1 << endl;
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











