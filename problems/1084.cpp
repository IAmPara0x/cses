

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n,m,k;
	cin >> n >> m >> k;


	vector<int> as(n);

	multiset<int> bs;


	for (int i = 0; i < n; i++) {
		cin >> as[i];
	}

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		bs.insert(x);
	}


	int count = 0;

	sort(as.begin(), as.end());
	for (int a: as) {
		auto itl = bs.lower_bound(a - k);

		if (itl != bs.end() && *itl <= a + k) {
			count ++;
			bs.erase(itl);
		}

	}

	cout << count << endl;
}
