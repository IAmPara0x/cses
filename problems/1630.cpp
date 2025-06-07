#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int,int>> tasks(n);

	for (auto &task: tasks) {
		cin >> task.first;
		cin >> task.second;
	}

	sort(begin(tasks), end(tasks));

	long long time = 0;
	long long ans = 0;

	for (auto &task: tasks) {

		time += task.first;
		ans += (task.second - time);
	}

	cout << ans << endl;

}
