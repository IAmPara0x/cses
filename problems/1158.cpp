#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,x; cin >> n >> x;
	vector<int> costs(n + 1,0), pages(n + 1,0);

	for (int i = 1; i <= n; i++) cin >> costs[i];
	for (int i = 1; i <= n; i++) cin >> pages[i];

	vector<vector<int>> dp(n + 1);

	for (int i = 0; i <= n; i++)
		dp[i].resize(x + 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= x; j++) {

			if (j < costs[i])
				dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = max(dp[i - 1][j - costs[i]] + pages[i], dp[i - 1][j]);
			}

		}
	}

	cout << dp[n][x];

}
