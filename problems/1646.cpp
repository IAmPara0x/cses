#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int n,q;

	cin >> n >> q;

	vector<long long> xs(n,0);

	for (int i = 0; i < n; i++)
		cin >> xs[i];


	vector<long long> sums(n + 1,0);


	for (int i = 1; i <= n; i++)
		sums[i] += xs[i - 1] + sums[i - 1];


	while (q--) {

		int a,b;

		cin >> a >> b;
		cout << sums[b] - sums[a - 1] << endl;
	}
	



}
