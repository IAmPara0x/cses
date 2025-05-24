#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	vector<tuple<int,int>> events(n * 2);

	for (int i = 0; i < n; i++) {
		int in,out;

		cin >> in >> out;

		events[2*i] = make_tuple(in, 1);
		events[2*i+1] = make_tuple(out, -1);

	}

	sort(events.begin(), events.end());

	int maxc = 0;
	int c = 0;

	for (auto e: events) {
		c += get<1>(e);
		maxc = max(c,maxc);
	}

	cout << maxc << endl;


}
