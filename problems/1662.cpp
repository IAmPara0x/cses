#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	vector<long long> xs(n + 1,0);

	for (int i = 1; i <= n; i++) {
		cin >> xs[i];
		// xs[i] = (xs[i] % n + xs[i - 1]) % n;
		xs[i] = ((xs[i] + xs[i - 1]) % n + n) % n;

	}

	map<long long,int> freq;

	long long count = 0;

	for (int i = 0; i <= n; i++) {

		count += freq[xs[i]];
		freq[xs[i]] ++;

	}

	cout << count << endl;


}
