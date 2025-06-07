#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	vector<ll> lens(n,0);
	for (auto &i: lens) cin >> i;

	sort(begin(lens), end(lens));

	ll median = lens[n / 2];
	cout << accumulate(lens.begin(), lens.end(), 0LL, [&](ll cost, ll l){ 
				return cost + llabs(l - median); 
	});
}
