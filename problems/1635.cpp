#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1000000007;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,x;
	cin >> n >> x;

	vector<int> coins(n,0);

	for (int i = 0; i < n; i++)
		cin >> coins[i];

	vector<long> dp(x + 1,0);

	sort(coins.begin(), coins.end());

	for (int i = 0; i < x + 1; i++) {

		for (auto c: coins) {

			if (i - c < 0)
				break;

			if (i - c == 0) {
				dp[i] += 1;
				continue;
			}

			if (dp[i - c] != 0 && dp[c] != 0) {
				// cout << format("i: {}, c: {}, i-c: {}, dp[c]: {}, dp[i - c]: {}\n", i, c, i - c, dp[c], dp[i - c]);
				dp[i] += dp[i - c];
			}


		}

		dp[i] %= MOD;


	}

	cout << dp[x] << endl;

}
