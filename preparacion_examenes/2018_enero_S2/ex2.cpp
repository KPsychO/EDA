#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void solve(int v[], int x, int a, int b, int &ret) {

	if (a < b) {

		int m = (a + b) / 2;

		if (abs(v[m] - x) < abs(x - ret))
			ret = v[m];
			

		if (v[m] > x)
			solve(v, x, a, m - 1, ret);

		else
			solve(v, x, m + 1, b, ret);

	}

	return;


}

int main() {

	int c, x, n, v[10000];

	cin >> c;

	while (c--) {

		cin >> x >> n;

		for (int i = 0; i < n; ++i)
			cin >> v[i];

		int ret = 99999;
		solve(v, x, 0, n - 1, ret);
		cout << ret << "\n";

	}

	return 0;
}