#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	vector<int> values(n,0);
	for (auto &i: values) cin >> i;


	vector<bool> dp;
	int s = accumulate(begin(values), end(values), 0);
	dp.resize(s + 1);
	dp[0] = true;
	dp[s] = true;

	for (int c: values) {
		for (int i = s; 0 <= i; i--)
			if (dp[i] and i + c <= s)
				dp[i + c] = true;
	}

	int count = 0;
	for (int i = 1; i <= s; i++) {
		if (dp[i])
			count++;
	}
	cout << count << endl;
	for (int i = 1; i <= s; i++) {
		if (dp[i])
			cout << i << " ";
	}
	cout << endl;

}
