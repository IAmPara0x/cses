#include <bits/stdc++.h>

using namespace std;


long first_true(long lo, long hi, function<bool(long)> f) {

	hi++;

	while (lo < hi) {
		long mid = lo + (hi - lo) / 2;
		if (f(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,k; cin >> n >> k;

	vector<int> xs(n);

	for (auto &i: xs) cin >> i;

	long lo = first_true(0,1e18,[&](long x){

			int blocks = 1;
			long long runningsum = 0;
			for (int i = 0; i < n; i++) {
				if (runningsum + xs[i] <= x) {
						runningsum += xs[i];
				} else {
						blocks++;
						runningsum = xs[i];
				}
			}

			return blocks <= k;
	});


	long long runningsum = 0;
	long long maxSoFar = 0;
	for (int i = 0; i < n; i++) {
		if (runningsum + xs[i] <= lo) {
				runningsum += xs[i];
		} else {
				runningsum = xs[i];
		}
		maxSoFar = max(maxSoFar, runningsum);
	}

	cout << maxSoFar << endl;

}
