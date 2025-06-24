#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<vector<int>> graph;
vector<int> ordering;


int n,m;
ll paths = 0LL;

const ll MOD = 1e9 + 7;


void kahn_topo_sort() {

  queue<int> q;

  vector<int> in_degree(n, 0);
  for (int i = 0; i < n; i++)
    for (auto dep: graph[i])
      in_degree[dep]++;



  for (int i = 0; i < n; i++)
    if (in_degree[i] == 0)
      q.push(i);


  while (!q.empty()) {
    auto node = q.front();
    q.pop();
    ordering.push_back(node);

    for (auto &neighbour: graph[node])
      if (--in_degree[neighbour] == 0)
	q.push(neighbour);

  }

  
}



int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  graph.resize(n);

  int a,b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
  }

  kahn_topo_sort();

  assert(ordering.size() == (unsigned long long)n);

  vector<ll> dp(n, 0);
  dp[0] = 1;

  for (int node: ordering) {
    for (int neighbour: graph[node])
      dp[neighbour] = (dp[node] + dp[neighbour]) % MOD;
  }

  cout << dp[n-1] % MOD << endl;


}
