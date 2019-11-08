#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool solve(int v[], int a, int b) {

	if ((b - a) < (v[b] - v[a]))
		return 0;

	// if (v[a] == v[b]) return 1; if (v[a] + 1 == v[b]) return 1;

	if ((a + 1) >= b) {

		if (v[b] - v[a] > 1)
			return 0;

		return 1;

	}

	int m = (a + b) / 2;

	bool bm, i, d;

	bm = (v[m] == v[m + 1] || v[m] + 1 == v[m + 1]);

	if (!bm)
		return 0;

	i = solve(v, a, m);

	if (!i)
		return 0;

	d = solve(v, m + 1, b);

	if (!d)
		return 0;
	
	return 1;

}

int main() {

	int n, v[1000];

	while (cin >> n && n) {

		for (int i = 0; i < n; ++i)
			cin >> v[i];

		bool k = solve(v, 0, n - 1);

		cout << k << "\n";

	}

	return 0;
}