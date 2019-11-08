#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// { Pre: (0 < n <= long(v) } 

void solve(int v[], int n) /* return ret && l */ {

	int l = 0;
	int a = 0;
	int b = 0;
	int laux = 0;
	int ret = 0;

	// { C: n - b }
	// { O(n) }

	/*
	
	{ I: ... }

	*/

	while (b < n) {

		if (v[b] == (v[a] + (b - a))) {

			b++;
			laux++;

		}
		else {

			if (laux > l) {

				l = laux;

				ret = a;

			}

			a = b;
			laux = 0;

		}

	}

	if (laux > l) {

		l = laux;

		ret = a;

	}

	cout << ret << " " << l << "\n";

}

// { Pos: ...}

int main() {

	int n, v[1000];

	while (cin >> n && n) {

		for (int i = 0; i < n; ++i)
			cin >> v[i];

		solve(v, n);

	}

	return 0;
}