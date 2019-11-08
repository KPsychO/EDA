#include <iostream>
#include <algorithm>

using namespace std;

// { Pre: (3 <= n < long(v)) ^ (0 < m <= n) ^ (s = Sum i : (0 <= i <= 2) : v[i]) }

int ex_1(int v[], int n, int m, int s) /* return ret */ {

	int a = 0;
	int b = m;
	int ret = s;
	int aux = s;

	// { C: n - b }
	// { O(n) }
	// { I: }

	while (b < n) {

		aux -= v[a];
		aux += v[b];

		ret = max(ret, aux);

		++a;
		++b;

	}

	return ret;
	
}

// { Pos: ret = max(Sum x : (i, j : (0 <= i <= x <= j < n) ^ (j = (i + m - 1)) : v[x]) }

int main() {

	int v[10000];
	int n;
	int m;
	int s;

	while (cin >> n && n){

		cin >> m >> s;

		for (int i = 0; i < n; ++i)
			cin >> v[i];

		cout << ex_1(v, n, m, s) << "\n";

	}

	return 0;
}