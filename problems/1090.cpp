#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,x;

	cin >> n >> x;

	vector<int> ys(n,0);

	for (int i = 0; i < n; i++)
		cin >> ys[i];

	sort(ys.begin(), ys.end());

	int i = 0, j = n - 1;
	int count = 0;

	while (i <= j) {

		if (ys[j] + ys[i] <= x) {
			j--;
			i++;
		} else {
			j--;
		}
		count ++;
	}

	cout << count << endl;

}
