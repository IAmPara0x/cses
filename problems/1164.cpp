#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int n; cin >> n;

	vector<pair<int,int>> customers(n);
	vector<int> coords(n,0), rooms(n,0);

	for (int i = 0; i < n; i++) {
		cin >> customers[i].first >> customers[i].second;
		coords[i] = i;
	}
	sort(begin(coords), end(coords), [&](int x, int y) {
			return customers[x] < customers[y];
	});
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;

	int room_no = 1;

	minHeap.push({customers[coords[0]].second, coords[0]});
	rooms[coords[0]] = room_no;
	room_no++;

	for (int i = 1; i < n; i++) {

		int idx = coords[i];

		auto element = minHeap.top(); 

		if (element.first < customers[idx].first) {
			rooms[idx] = rooms[element.second];
			minHeap.pop();
		} else {
			rooms[idx] = room_no;
			room_no++;
		}
		minHeap.push({customers[idx].second, idx});
	}

	cout << minHeap.size() << endl;

	// for (int i = 0; i < n; i++) {
	// }

	for (auto &room : rooms)
		cout << room << " ";


}
