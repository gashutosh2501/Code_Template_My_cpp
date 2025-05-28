#include<iostream>
#include<vector>
using  namespace std;
class DSU {
public:
	vector<int>SP;
	vector<int>rank;
	int components;

	//Constructor
	DSU(int n) {
		SP.resize(n, -1);
		rank.resize(n, 1);
		components = n;
	}

	int FindS(int node) {
		//Return me the superparent.
		if (SP[node] == -1) {
			return node;
		}
		//Path Compression
		return SP[node] = FindS(SP[node]);
	}

	void UnionU(int x, int y) {
		//Union By Rank
		int S1 = FindS(x);
		int S2 = FindS(y);

		if (S1 != S2) {
			//Union Them.
			if (rank[S1] < rank[S2]) {
				SP[S1] = S2;
				rank[S2] += rank[S1];
			} else {
				SP[S2] = S1;
				rank[S1] += rank[S2];
			}
			components--;
		}
	}
};


class Graph {
	vector<vector<int>>edgelist;
	int nodes;

public:
	Graph(int nodes) {
		this->nodes = nodes;
	}

	void addEdge(int x, int y, int w) {
		edgelist.push_back({w, x, y});
	}

	int Kruskal_MST() {
		DSU g(nodes);

		int Minimum_Weight = 0;

		sort(edgelist.begin(), edgelist.end());

		for (vector<int> x : edgelist) {
			int weight = x[0];
			int V1 = x[1];
			int V2 = x[2];


			//Visited Check:
			//DSU:
			if (g.FindS(V1) != g.FindS(V2)) {
				g.UnionU(V1, V2);
				Minimum_Weight += weight;
			}
		}

		return Minimum_Weight;
	}
};



int main() {

}






















