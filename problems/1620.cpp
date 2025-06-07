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
 
	int n; cin >> n;
	unsigned int t; cin >> t;
	vector<int> xs(n);
 
	for (int &i: xs) cin >> i;
 
	cout << first_true(1,1e18, [&](long x){
			unsigned long long y = 0;
			for (int i = 0; i < n; i++)
				if (t <= y)
					return true;
				else
					y += x / xs[i];
		return t <= y;
	}) << endl;
 
}

