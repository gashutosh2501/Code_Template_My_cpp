#include<iostream>
#include<list>
#include<vector>
#include<map>
#include<set>
#include<climits>
using  namespace std;
template<typename T>


class Graph {
	map < T, list<pair<T, int>>>mp; //Adj. List
	map<T, bool>visited;


public:
	void AddEdge(T x, T y, int w) {
		mp[x].push_back({y, w});
		mp[y].push_back({x, w});
	}

	void Dijkstras(T scr, T des) {
		map<T, int>distance;
		set < pair<int, T> >s;

		for (auto x : mp) {
			distance[x.first] = INT_MAX;
		}

		distance[scr] = 0;
		s.insert({0, scr});

		while (!s.empty()) {

			pair<int, T> f = *(s.begin());
			s.erase(s.begin());

			T node = f.second;
			int dist = f.first;

			/*

				For Every element of this mp[node] that is going
				to be represented as child do the ttask.


				what is the type of mp[node]:

				mp[node] is a list of pair<T,int>

				and since we are saying for every element of this list
				 do the task

				hence type of this child will be pair<T,int>
				as very element of the list is a pair.

			*/

			for (pair<T, int> child : mp[node]) {
				//This is an egde weight of node to child
				int edgeweight = child.second;
				if (distance[child.first] > dist + edgeweight) {
					auto f = s.find({distance[child.first], child.first});
					if (f != s.end()) {
						s.erase(f);
					}
					//Insert thee node with new value.
					distance[child.first] = dist + edgeweight;
					s.insert({distance[child.first], child.first});
				}
			}
		}

		for (auto x : mp) {
			cout << "Distance of " << x.first << " from " << scr << " : " << distance[x.first] << endl;
		}
	}

};

int main() {
	int n, m;
	cin >> n >> m;

	Graph<int>gr;

	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		gr.AddEdge(x, y, w);
	}

	gr.Dijkstras(0, 3);
}















