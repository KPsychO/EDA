#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void solve(int v[], int n, int d, int e, int i, int cont) {

	if (i < n) {

		v[i] = e;

		if (i == (n - 1)) {

			cout << v[0];
			for (int i = 1; i < n; ++i)
				cout << " " << v[i];
			cout << '\n';

		}

		if (cont < d)
			solve(v, n, d, e, i + 1, cont + 1);

		solve(v, n, d, e + 1, i + 1, 1);

	}

}

int main() {

	int n, d, e, v[10000];

	while (cin >> n >> d >> e && n) {

		solve(v, n, d, e, 0, 1);

	}

	return 0;
}