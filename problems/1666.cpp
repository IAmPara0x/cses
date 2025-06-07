#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> roads;
vector<bool> visited;


void dfs(int x) {
	if (visited[x]) return;
	visited[x] = true;
	for (auto &r: roads[x]) {
		dfs(r);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	roads.resize(n+1);
	visited.resize(n+1,false);

	for (int i = 0; i < m; i++) {
		int a,b; cin >> a >> b;
		roads[a].push_back(b);
		roads[b].push_back(a);
	}

	dfs(1);

	int count = 0;
	vector<pair<int,int>> newroads;
	for (int i = 2; i <= n; i++) {

		if (!visited[i]) {
			dfs(i);
			count++;

			newroads.push_back({i-1,i});
		}

	}

	cout << count << endl;
	for (auto &newroad: newroads) {
		cout << newroad.first << " " << newroad.second << endl;
	}
}
