#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,x;
	cin >> n >> x;

	vector<long long> xs(n + 1,0);

	for (int i = 1; i <= n; i++)
	{
		cin >> xs[i];
		xs[i] += xs[i - 1];
	}



	map<long long,int> freq;
	long long count = 0;

	for (int i = 0; i <= n; i++) {

		count += freq[xs[i] - x];
		freq[xs[i]] += 1;

	}

	cout << count << endl;

}
