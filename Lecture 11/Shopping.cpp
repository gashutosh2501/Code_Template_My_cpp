#include<iostream>
#include<vector>
#include<queue>

using  namespace std;
#define int long long

int col, row;
int dist[26][26] {0};

int dx[] {0, 0, 1, -1};
int dy[] {1, -1, 0, 0};

char a[25][25];
int scr_x, scr_y;
int des_x, des_y;

bool IsPossible(int x, int y) {
	return (x >= 0 and x<row and y >= 0 and y < col and a[x][y] != 'X');
}


void Dijkstras() {

	dist[scr_x][scr_y] = 0;
	queue<pair<int, int>>q;
	q.push({scr_x, scr_y});

	while (!q.empty()) {

		auto x = q.front();
		q.pop();

		int current_x = x.first;
		int current_y = x.second;

		for (int i = 0; i < 4; i++) {

			int next_x = current_x + dx[i];
			int next_y = current_y + dy[i];

			if (IsPossible(next_x, next_y) == 1 and
			        (dist[next_x][next_y] > dist[current_x][current_y] +
			         a[current_x][current_y] - '0')) {


				dist[next_x][next_y] = dist[current_x][current_y] +
				                       a[current_x][current_y] - '0';

				q.push({next_x, next_y});
			}

		}

	}

}


int32_t main() {

	cin >> col >> row;

	while (col and row) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {

				char ch;
				cin >> ch;
				a[i][j] = ch;

				if (a[i][j] == 'S') {
					scr_x = i, scr_y = j;
					a[i][j] = '0';
				} else if (a[i][j] == 'D') {
					des_x = i, des_y = j;
					a[i][j] = '0';
				}

				dist[i][j] = 1e9;
			}
		}

		Dijkstras();
		cout << dist[des_x][des_y] << endl;
		cin >> col >> row;
	}


}