#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	vector<tuple<int,int>> events(n);

	for (int i = 0; i < n; i++) {
		int in,out;

		cin >> in >> out;
		events[i] = make_tuple(in,out);
	}

	sort(events.begin(), events.end(), [](const auto &a, const auto &b) {

			if (get<1>(a) == get<1>(b))
				return (get<1>(a) - get<0>(a)) < (get<1>(b) - get<0>(b));
			return get<1>(a) < get<1>(b);
	});
	

	int maxc = 0;
	int curr_et = 0;
	
	for (auto e: events) {
		if (curr_et <= get<0>(e)) {
			maxc++;
			curr_et = get<1>(e);
		}
	}

	cout  << maxc << endl;

}
