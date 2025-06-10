#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	vector<int> dp(n + 1, 1e9);
	
	dp[0] = 0;

	for (int i = 1; i <= n; i++) {

		int num = i;

		while (0 < num) {
			dp[i] = min(dp[i - num % 10] + 1, dp[i]);
			num /= 10;
		}

	}

	cout << dp[n] << endl;

}
