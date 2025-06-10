#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int c,x; cin >> c >> x;

	vector<int> coins(c, 0);
	for (auto &i: coins) cin >> i;

	sort(begin(coins),end(coins));

	vector<long long> dp(x + 1, 0);

	dp[0] = 1;

	for (auto coin : coins) {

		for (int i = 1; i <= x; i++) {
			if (0 <= i - coin)
				dp[i] += dp[i - coin] % MOD;
		}
	}

	cout << dp[x] % MOD << endl;

}
