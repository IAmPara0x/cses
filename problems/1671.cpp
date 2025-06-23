#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

vector<vector<pair<int,ll>>> graph;
vector<bool> visited;
vector<ll> distances;
int n,m;

void dijkstra(int snode) {
  distances[snode] = 0;

  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> minHeap;

  minHeap.push({0,snode});

  while (!minHeap.empty()) {

    auto [dist, node] = minHeap.top();
    minHeap.pop();

    if (visited[node]) continue;

    visited[node] = true;

    for (auto &[neighbour, cost]: graph[node]) {

      ll fdist = cost + dist;

      if (fdist < distances[neighbour]) {
	distances[neighbour] = fdist;
	minHeap.push({fdist, neighbour});
      }

    }

  }
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  graph.resize(n);

  visited.resize(n);
  visited.assign(n, false);

  distances.resize(n);
  distances.assign(n, ULLONG_MAX);


  int a,b,c;

  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    a--;b--;
    graph[a].push_back({b,c});
  }

  dijkstra(0);

  for (auto &dist: distances)
    cout << dist << " ";
  cout << endl;

}
