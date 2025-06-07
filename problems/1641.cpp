#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,x;

	cin >> n >> x;
	vector<pair<int,int>> xs(n);

	for (int i = 0; i < n; i++) {
		cin >> xs[i].first;
		xs[i].second = i + 1;
	}

	sort(xs.begin(),xs.end());

	bool found = false;

	for (int l = 0; l < n - 2; l++) {

		int m = l + 1;
		int r = n - 1;
		while (m < r) {

			int sum = xs[l].first + xs[m].first + xs[r].first;

			if (x < sum)
				r--;
			else if (sum < x)
				m++;
			else {
				found = true;
				cout << xs[l].second << " " << xs[m].second << " " << xs[r].second;
				return 0;
			}
				
		}
	}

	if (!found)
		cout << "IMPOSSIBLE";

}
