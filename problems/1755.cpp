
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	unordered_map<char, int> freqs;

	string xs;

	cin >> xs;

	for (char a = 'A'; a <= 'Z'; a++)
		freqs[a] = 0;

	for (char x: xs) {
		freqs[x] += 1;
	}

	bool possible = true;

	if (xs.size() % 2 == 0) {

		for (const auto &pair: freqs) {
			if (pair.second % 2 != 0) {
				possible = false;
				break;
			}
		}

		if (possible) {

			std::string palindrome(xs.size(), '\0');

			int i = 0,j = xs.size();

			for (char a = 'A'; a <= 'Z'; a++) {

				int r = freqs[a] / 2;

				for (int k = 0; k < r; k++) {
					palindrome[i + k] = a;
					palindrome[j - k - 1] = a;
				}

				i += r;
				j -= r;

			}

		cout << palindrome << endl;

		} else cout << "NO SOLUTION" << endl;


	} else {

		int count = 0;
		char c;

		for (const auto &pair: freqs) {
			if (pair.second % 2 != 0 && count == 1) {
				possible = false;
				break;
			}
			if (pair.second % 2 != 0) {
				c = pair.first;
				count += 1;
			}
		}


		if (possible) {

			std::string palindrome(xs.size(), '\0');

			int i = 0,j = xs.size();

			for (char a = 'A'; a <= 'Z'; a++) {

				int r = freqs[a] / 2;

				for (int k = 0; k < r; k++) {
					palindrome[i + k] = a;
					palindrome[j - k - 1] = a;
				}

				i += r;
				j -= r;

			}

		  palindrome[xs.size() / 2] = c;

		  cout << palindrome << endl;
		} else cout << "NO SOLUTION" << endl;


	}



}

