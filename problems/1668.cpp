#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> team;

bool dfs(int x,int color) {
	// if (visited[x]) return;
	
	if (visited[x]) {
		if (team[x] != color)
			return false;
		else
			return true;
	}

	visited[x] = true;
	team[x] = color;

	for (auto &i: adj[x]) {
		if (!dfs(i, (color % 2) + 1)) return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;

	adj.resize(n + 1);
	visited.resize(n + 1,0);
	team.resize(n + 1,0);

	for (int i = 0; i < m; i++) {
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bool p = dfs(1,1);
	if (!p) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	for (int i = 2; i <= n; i++) {

		if (!visited[i]) {
			p = dfs(i,1);
			if (!p) {
				cout << "IMPOSSIBLE";
				return 0;
			}
		}

	}


	for (int i = 1; i <= n; i++)
		cout << team[i] << " ";
	cout << endl;

}
