#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,x; cin >> n >> x;

	vector<int> xs(n,0);

	for (auto &i: xs)
		cin >> i;

	int l = 0, r = 0, s = xs[0], count = 0;

	while (l != n and r != n) {

		if (s < x) {
			r++;
			s += xs[r];
		} else  {

			 if (s == x)
				count ++;

			s -= xs[l];
			l++;
		}
	}

	cout << count << endl;

}


