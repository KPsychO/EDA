//#include <iostream>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//
//void solve(int v[], int n, int e, int k, int cont, int caux, int pres) {
//
//	if (k < n) {
//
//		v[k] = e;
//
//		if (k == (n - 1)) {
//
//			cout << v[0];
//			for (int i = 1; i < n; ++i)
//				cout << ' ' << v[i];
//			cout << '\n';
//
//			return;
//
//		}
//
//		solve(v, n, e, k + 1, cont + 1, caux, pres - 1);
//			
//		if (cont < caux)
//			solve(v, n, e, k + 1, cont + 1, caux, pres - 1);
//
//		else if (pres >= cont && pres >= caux) {
//					   
//			solve(v, n, e + 1, k + 1, 1, cont, pres - 1);
//		
//		}
//
//	}
//	
//}
//
//int main() {
//
//	int n, v[10000];
//
//	while (cin >> n && n) {
//
//		solve(v, n, 1, 0, 1, 1, n - 1);
//
//	}
//
//}


#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve(int v[], int a, int b, int &primero, int &ultimo, int &ancho) {

	if (v[a] != v[b]) {

		int iprim = 0, iult = 0, ianc = 0;
		int dprim = 0, dult = 0, danc = 0;
		int m = (a + b) / 2;

		solve(v, a, m, iprim, iult, ianc);
		solve(v, m + 1, b, dprim, dult, danc);

		primero = iprim;
		ultimo = dult;
		ancho = max(ianc, danc);

		if (v[m] == v[m + 1])
			ancho = max(ancho, (iult + dprim));

		if (v[a] == v[m + 1 ])
			primero = (iprim + dprim);

		if (v[m] == v[b])
			ultimo = (iult + dult);

		return;

	}

	primero = ultimo = ancho = (b - a + 1);

}

int main() {

	int n, v[1000];
	int primero = 0, ultimo = 0, ancho = 0;

	while (cin >> n && n) {

		for (int i = 0; i < n; ++i)
			cin >> v[i];

		solve(v, 0, n - 1, primero, ultimo, ancho);

		cout << primero << " " << ultimo << " " << ancho << "\n";

	}

	return 0;
}