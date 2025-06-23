#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> graph;
vector<vector<char>> parents;
vector<vector<bool>> visited;
int n,m;


int bfs(int startRow, int startCol) {

  queue<pair<pair<int,int>,char>> q;

  q.push({{ startRow, startCol}, '\0'});

  while(!q.empty()) {

    auto [loc, move] = q.front();
    auto [row,col] = loc;
    q.pop();

    if (row < 0 or n <= row) continue;
    if (col < 0 or m <= col) continue;

    if (visited[row][col]) continue;

    visited[row][col] = true;
    parents[row][col] = move;

    if (graph[row][col] == 'B')
      return 0;


    q.push({{row - 1, col}, 'U'});
    q.push({{row + 1, col}, 'D'});
    q.push({{row, col - 1}, 'L'});
    q.push({{row, col + 1}, 'R'});

  }

  return -1;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  graph.resize(n);
  graph.assign(n, vector<char>(m));

  visited.resize(n);
  visited.assign(n, vector<bool>(m, false));

  parents.resize(n);
  parents.assign(n, vector<char>(m, '\0'));


  pair<int,int> snode, enode;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char tmp; cin >> tmp;

      if (tmp == '#')
	visited[i][j] = true;

      if (tmp == 'A')
	snode = {i,j};

      if (tmp == 'B')
	enode = {i,j};

      graph[i][j] = tmp;

    }
      

  int r = bfs(snode.first, snode.second);

  if (r != -1) {
    cout << "YES" << endl;

    vector<char> path;
    auto node = enode;

    while (node != snode) {
      char move = parents[node.first][node.second];

      if (move == 'U')
	node.first++;
      else if (move == 'D')
	node.first--;
      else if (move == 'L')
	node.second++;
      else
	node.second--;
      path.push_back(move);
    }

    reverse(begin(path), end(path));

    cout << path.size() << endl;

    for (auto x: path)
      cout << x;
    cout << endl;

  } else
    cout << "NO" << endl;

}
