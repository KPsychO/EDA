#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*

//#####################################
//  # DESCOMENTAR EN ACEPTA EL RETO #
//#####################################

inline void out(int n)
{
	int N = n, rev, count = 0;
	rev = N;
	if (N == 0) {
		putchar_unlocked('0');
		putchar_unlocked('\n');
		return; }
	while ((rev % 10) == 0) { count++; rev /= 10; }
	rev = 0;
	while (N != 0) { rev = (rev << 3) + (rev << 1) + N % 10; N /= 10; }
	while (rev != 0) { putchar_unlocked(rev % 10 + '0'); rev /= 10; }
	while (count--) putchar_unlocked('0');
	putchar_unlocked('\n');
}

inline void in(int &n)
{
	n = 0;
	int ch = getchar_unlocked(); int sign = 1;
	while (ch < '0' || ch > '9') { if (ch == '-')sign = -1; ch = getchar_unlocked(); }

	while (ch >= '0' && ch <= '9')
		n = (n << 3) + (n << 1) + ch - '0', ch = getchar_unlocked();
	n = n * sign;
}
*/

inline void out(int n)
{
	int N = n, rev, count = 0;
	rev = N;
	if (N == 0) {
		putchar('0');
		putchar('\n');
		return;
	}
	while ((rev % 10) == 0) { count++; rev /= 10; }
	rev = 0;
	while (N != 0) { rev = (rev << 3) + (rev << 1) + N % 10; N /= 10; }
	while (rev != 0) { putchar(rev % 10 + '0'); rev /= 10; }
	while (count--) putchar('0');
	putchar('\n');
}

int main() {

	int num_casos, n;

	in(num_casos);

	while (num_casos--) {

		in(n);

		if (n == 0)
			out(1);
		else if (n == 3)
			out(6);
		else if (n < 5)
			out(n);
		else 
			out(0);

	}

	return 0;
}