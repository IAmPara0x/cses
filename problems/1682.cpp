#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int x) {
	if (visited[x]) return;
	visited[x] = true;
	for (auto &i: adj[x]) {
		dfs(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m; cin >> n >> m;

	adj.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}


	vector<pair<int,int>> partitions;

	dfs(1);

	for (int i = 2; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			partitions.push_back({i - 1, i});
		}
	}

	if (partitions.size() == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	for (auto &p: partitions) {
		cout << p.first << " " << p.second;
	}




}
