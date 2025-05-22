#include <bits/stdc++.h>

using namespace std;

int m,n;
int rooms = 0;
vector<bool> visited;
vector<tuple<int,int>> moves = {make_tuple(-1,0), make_tuple(1,0), make_tuple(0,-1), make_tuple(0,1)};


bool isvalid(int y, int x) {
	if (x < 0 or y < 0 or m <= y or n <= x)
		return false;

	if (visited[y * n + x])
		return false;
	return true;
}

void dfs(int i, int j) {
	for (auto move : moves) {
		int y = i + get<0>(move);
		int x = j + get<1>(move);

		if (isvalid(y,x)) {
			visited[y * n + x] = true;
			dfs(y,x);
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n;

	visited.resize(n * m, false);

	char ch;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cin >> ch;
			if (ch == '#')
				visited[i * n + j] = true;
		}


	for (int dy = 0; dy < m; dy++)
		for (int dx = 0; dx < n; dx++) 
			if (isvalid(dy,dx)) {
				visited[dy * n + dx] = true;
				dfs(dy,dx);
				rooms++;
			}

	cout << rooms << endl;

	// for (int dy = 0; i < m; i++)
	// 	for (int dx = 0; j < n; j++) {
	// 		if (isvalid(i,j)) {
	// 			visited[i * j] = true;
	// 			dfs(i,j);
	// 			rooms++;
	// 		}
	// 	}



}
