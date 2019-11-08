#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void solve(int v[], int n, int e, int k, int cont, int caux, int pres) {

	if (k < n) {

		v[k] = e;

		if (k == (n - 1)) {

			cout << v[0];
			for (int i = 1; i < n; ++i)
				cout << ' ' << v[i];
			cout << '\n';

			return;

		}

		solve(v, n, e, k + 1, cont + 1, caux, pres - 1);
			
		if (cont < caux)
			solve(v, n, e, k + 1, cont + 1, caux, pres - 1);

		else if (pres >= cont && pres >= caux) {
					   
			solve(v, n, e + 1, k + 1, 1, cont, pres - 1);
		
		}

	}
	
}

int main() {

	int n, v[10000];

	while (cin >> n && n) {

		solve(v, n, 1, 0, 1, 1, n - 1);

	}

}