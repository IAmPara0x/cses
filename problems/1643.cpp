#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<long long> xs(n,0);

	for (int i = 0; i < n; i++)
		cin >> xs[i];


	long long m = xs[0];
	long long max_so_far = xs[0];

	for (int i = 1; i < n; i++) {


		// Make a decision on whether to select the current element or not.
		max_so_far = max(max_so_far + xs[i], xs[i]);

		// Does the decision made is previous step is better than the current max?
		// if so update it.
		m = max(m, max_so_far);
	}
	cout << m << endl;
}
