#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// { Pre: 0 < n <= long(v) ^ 0 < d <= n }

bool solve(int v[], int d, int n) /* return ret */ {

	int i = 0;
	int tam = 1;
	bool valid = 1;

	// { O(n) }
	// { C: n - i - 1 }

	/*
		{ I: (0 <= i < n) ^ tam = (P.t k, j : (0 <= k <= j < i) ^ (v[k] = v[j]) : j - k)) ^ tam < d  ^ valid = P.t k, j : 0 <= k <= j < i : v[k] = v[j] v v[k] + 1 = v[j]
	*/
	
	while ((i + 1 < n) && valid) {

		if (v[i] == v[i + 1] || v[i] + 1 == v[i + 1]) {

			if (v[i] == v[i + 1]) {
			++tam;

			if (tam > d)
				valid = 0;
		}
		else
			tam = 1;

		}
		else
			valid = 0;
		++i;

	}

	return valid;

}

/*
	{ Pos: ret = CPLP(v, n) ^ DD(v, d, n)
	Siendo:
		CPLP(v, n) = P.t k, j : 0 <= k <= j < n : v[k] = v[j] v v[k] + 1 = v[j]
		DD(v, n, d) = P.t k, j : (0 <= k <= j < n) ^ (v[k] = v[j]) : j - k < d

	}
*/

int main() {

	int d, n, v[10000];

	while (cin >> d >> n && d && n) {

		for (int i = 0; i < n; ++i)
			cin >> v[i];

		if (solve(v, d, n))
			cout << "SI\n";
		else
			cout << "NO\n";

	}

	return  0;

}