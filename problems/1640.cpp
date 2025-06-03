#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,x; cin >> n >> x;

	vector<pair<long long,int>> xs(n);

	for (int i = 0; i < n; i++) {
		cin >> xs[i].first;
		xs[i].second = i + 1;
	}

	sort(xs.begin(), xs.end());

	int i = 0, j = n - 1;
	bool found = false;

	while (i < j) {

		long long sum = xs[i].first + xs[j].first;

		if (sum == x) {
			found = true;
			break;
		}

		if (sum < x)
			i++;
		else
			j--;

	}

	if (found and i != j)
		cout << xs[i].second << " "<< xs[j].second << endl;
	else
		cout << "IMPOSSIBLE" << endl;



}
