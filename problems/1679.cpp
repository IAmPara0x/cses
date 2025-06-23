#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

vector<vector<int>> graph;
vector<int> ordering;
int n,m;

void kahn_topo_sort() {


  vector<int> in_degree(n, 0);

  for (int i = 0; i < n; i++)
    for (auto dep: graph[i])
	in_degree[dep]++;


  queue<int> q;
  for (int i = 0; i < n; i++)
    if (in_degree[i] == 0)
      q.push(i);


  while (!q.empty()) {
    int node = q.front();
    q.pop();
    ordering.push_back(node);
    for (auto &neighbour: graph[node])
      if (--in_degree[neighbour] == 0)
	q.push(neighbour);
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  graph.resize(n);

  int a,b;
  for (int j = 0; j < m; j++) {
      // b depends on a: a -> b
    cin >> a >> b; a--; b--;
    graph[a].push_back(b);
   }

  kahn_topo_sort();


  if (ordering.size() != (ll)n)
    cout << "IMPOSSIBLE" << endl;
  else
    for (auto &node: ordering)
	cout << node + 1 << " ";
  cout << endl;

}
