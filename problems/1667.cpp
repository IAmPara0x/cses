#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> parents;
vector<bool> visited;
int n,m;


int bfs(int snode, int enode) {

  queue<pair<int,int>> q;

  q.push({snode, 0});
  visited[snode] = true;

  while(!q.empty()) {

    auto [node, dist] = q.front();
    q.pop();
      
    if (node == enode)
      return dist;

    for (auto &neighbour: graph[node]) {
      if (!visited[neighbour]) {
	q.push({neighbour, dist + 1});
	parents[neighbour] = node;
	visited[neighbour] = true;
      }
    }

  }

  return -1;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  graph.resize(n);

  visited.resize(n);
  visited.assign(n, false);

  parents.resize(n);
  parents.assign(n, -1);

  int a,b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int r = bfs(0, n - 1);

  if (r != -1) {
    r++;
    cout << r << endl;
    vector<int> path;
    int node = n - 1;

    while (r--) {
      path.push_back(node + 1);
      node = parents[node];
    }
    reverse(begin(path), end(path));

    for (auto &x: path)
      cout << x << " ";
    cout << endl;

  }
  else
    cout << "IMPOSSIBLE" << endl;
}
