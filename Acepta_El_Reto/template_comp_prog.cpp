
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define fork(i, k, n) for (int i = (int)(k); i < (int)(n); ++i)
#define rforn(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rfor1(i, n) for (int i = (int)(n); i >= 1; --i)
#define rfork(i, k, n) for (int i = (int)(n) - 1; i >= (int)(k); --i)
#define bit_at(x, i) (x & (1 << i))
#define bit_on(x, i) (x |= (1 << i))
#define bit_off(x, i) (x &= ~(1 << i))
#define bit_flip(x, i) (x ^= (1 << i))
#define set_n_bits_on(x, n) (x = 0), (x = (1 << n) - 1) // OVERFLOW!!!
#define num_bits_on(x) __builtin_popcount(x) // long long ---> __builtin_popcountll
#define lsb(x) (x & (-x)) // alt --->  (1 + __builtin_ctz(x))
#define leading_zeros(x) __buitin_clz(x)
#define watch(x) cerr << #x << " = " << x << '\n';
#define watch_o(x) cout << #x << " = " << x << '\n';
#define watch_l(x) cerr << #x << " = " << x << " ";
#define watch_ol(x) cout << #x << " = " << x << " ";
#define PI acos(-1)
#define INF 1e9
#define EPS 1e-5
#define MOD (int)(1e9) + 7
#define bn '\n'

template <class T> bool uin(T & a, T b) { return a > b ? (a = b, true) : false; }
template <class T> bool uax(T & a, T b) { return a < b ? (a = b, true) : false; }
template <class T>
ostream& operator<<(ostream & o, vector<T> const& v) {
	for (size_t i = 0; i < v.size() - 1; ++i)
		o << v[i] << ' ';
	if (!v.empty())
		o << v.back();
	return o;
}

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef pair<int, ii> i_ii;
typedef vector<i_ii> vi_ii;
typedef vector<string> vs;

int main(){
	
	

	return 0;
}
