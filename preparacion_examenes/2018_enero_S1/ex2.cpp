#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int solve(int v[], int a, int b) {

	if (a < b) {

		int m = (a + b) / 2;

		if (v[m] % 2)
			return v[m];

		if (v[m] / 2 < (m + 1))
			return solve(v, a, m - 1);

		return	solve(v, m + 1, b);
	}

	return -1;

}

int main() {

	int n, v[1000];

	while (cin >> n && n) {

		for (int i = 0; i < n; ++i)
			cin >> v[i];

		cout << solve(v, 0, n) << "\n";

	}

	return 0;
}