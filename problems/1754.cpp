#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int a,b;
		cin >> a >> b;

		int diff = abs(a - b);

		if (a < b) {
			a -= diff;
			b -= 2*diff;
		} else {
			a -= 2*diff;
			b -= diff;
		}

		if (0 <= a and 0 <= b and a % 3 == 0 and b % 3 == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}

}
