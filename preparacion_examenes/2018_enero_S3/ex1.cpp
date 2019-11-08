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
//		if (cont < caux)
//			solve(v, n, e, k + 1, cont + 1, caux, pres - 1);
//
//		solve(v, n, e, k + 1, cont + 1, caux, pres - 1);
//
//		if (pres >= cont && pres >= caux) {
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
#include <algorithm>
#include <cmath>

using namespace std;

// { Pre: 0 < n <= long(v) ^ (P.t x, y : (0 <= x < y <= n) : (v[x] <= v[y])) }

bool solve(int v[], int n) {

	int i = 1, escact = 1, escant = 1; // escact = escalon actual ^ escant = escalon anterior (máximo)
	bool ret = 1;

	// { O(n) }
	// {C: n - i }
	/*
	{ I:  	ret = crecientes(v, n) donde: crecientes(v, i) : (Pt. x, y : (0 <= x <= y < i) : (#a : (0 <= a <= x) : v[a] = v[a+1]) <= (#b : (x < b <= y) : v[b] = v[b+1])) ^ 
			escact = (#a : (0 <= a < i) : (v[a] = v[i - 1])) ^
			escant = max m : (#a : (0 <= a < i ) : (#b : 0 <= b < a : (v[a] = v[b]) ^ (v[b] != v[i - 1]))) : m
	}
	*/
	
	while ((i < n) && ret) {

		if (v[i - 1] != v[i]) {

			if (escant > escact)
				ret = 0;

			else {
				escant = escact;
				escact = 1;
			}

		}
		else
			++escact;

		++i;

	}

	if (escant > escact)
		ret = 0;
	
	return ret;

}

/*
 { Pos: ret = crecientes(v, n)
	donde: crecientes(v, n) : 
		(Pt. x, y : (0 <= x < y < n) ^ (x = y - 1) ^ (v[x] != v[y]) :
		(#a : (0 <= a <= x) : v[a] = v[a+1]) <=	(#b : (y <= b < n) : v[b] = v[b+1]))	

	También es correcto si:

	donde: crecientes(v, n) : 
		(Pt. x, y : (0 <= x <= y < n) :
		(#a : (0 <= a <= x) : v[a] = v[a+1]) <=	(#b : (y <= b <= n) : v[b] = v[b+1]))
 }
*/

int main() {

	int n, v[1000];

	while (cin >> n && n) {

		for (int i = 0; i < n; ++i)
			cin >> v[i];

		solve(v, n) ? (cout << "SI\n") : (cout << "NO\n");

	}
	
	return 0;
}