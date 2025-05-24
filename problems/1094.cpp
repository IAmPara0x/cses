// #include <io
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;

	cin >> n;

	vector<long> xs(n,0);

	for (int i = 0; i < n; i++)
		cin >> xs[i];

	long moves = 0;
	for (int i = 1; i < n; i++) {
		if (xs[i - 1] <= xs[i])
			continue;

		moves += xs[i - 1] - xs[i];
		xs[i] = xs[i - 1];

	}

	cout << moves << endl;

	return 0;
}
