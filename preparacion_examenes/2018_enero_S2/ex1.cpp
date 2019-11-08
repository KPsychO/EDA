#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// { Pre: 0 < n <= long(v) }

int solve(int v[], int n) /* return ret */ {

	int i = 1;
	int aux = v[i - 1];
	int tam = 1;
	int ret = -1;

	// { C: n - i }
	// { O(n) }

	// { I: i = (0 < i < n) ^ aux = v[i-1] ^ tam = (#j : 0 < j < i : v[j - 1] >= v[j] ^ ret = (max(ret, tam) }

	while (i < n) {

		if (aux >= v[i])
			++tam;

		else {
			ret = max(ret, tam);
			tam = 1;
		}

		aux = v[i];
		++i;

	}

	ret = max(ret, tam);

	return ret;

}

// { Pos: ret = #i : (0 < i < n) : v[i - 1] >= v[i] }

int main() {

	int c, n, v[1000];

	cin >> c;

	while (c--) {

		cin >> n;

		for (int i = 0; i < n; ++i)
			cin >> v[i];

		cout << solve(v, n) << "\n";

	}

	return 0;
}