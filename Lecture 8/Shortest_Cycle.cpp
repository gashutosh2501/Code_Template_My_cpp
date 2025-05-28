#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using  namespace std;

vector<int>gr[100005];

//Only when we are sure inputs are of integers.


void bfs(int scr, int n, int &ans) {
	vector<int>distance(n + 1, INT_MAX);
	queue<int>q;
	q.push(scr);
	distance[scr] = 0;

	while (!q.empty()) {

		int node = q.front();
		q.pop();

		/*
			for every element in the container
			gr[node] i.e. going to be represented
			as nbr do the task assigned.

		*/

		for (int nbr : gr[node]) {

			if (distance[nbr] == INT_MAX) {
				q.push(nbr);
				distance[nbr] = distance[node] + 1;
			} else if (distance[nbr] >= distance[node]) {

				//When you have a backedge.
				//This proves there is a cycle.

				int current_length = distance[node] + distance[nbr] + 1;
				ans = min(ans, current_length);
			}
		}
	}
}



int main() {

	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}


	//Minimum Cycle Length.
	int ans = n + 1;//Pressume there is no cycle.


	//I know the range of nodes.
	for (int i = 0; i < n; i++) {
		bfs(i, n, ans);
	}

	if (ans == n + 1) {
		cout << "No cycle" << endl;
	} else {
		cout << ans << endl;
	}

	printf("%s\n", "Myank" );

}




























