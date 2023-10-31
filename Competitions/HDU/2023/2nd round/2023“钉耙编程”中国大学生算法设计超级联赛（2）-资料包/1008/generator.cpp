#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

void randomData(int n, int q, double p) {
	cout << n << "\n";
	for (int i = 0; i < 7; ++i) {
		cout << rnd.next(1, 100000000) << " \n"[i == 6];
	}
	string s(n + 1, '.'), mp = "helowrd";
	for (int i = 1; i <= n; ++i) {
		s[i] = mp[rnd.next(7)];
	}
	cout << q << "\n";
	for (int i = 0; i < q; ++i) {
		if (rnd.next() < p) {
			int idx = rnd.next(1, n);
			cout << "1 " << idx << " " << s[idx] << "\n";
		} else {
			int L = (n - 1) / 4 + 1, R = n - n / 4;
			int l = rnd.next(1, L), r = rnd.next(R, n);
			cout << "2 " << l << " " << r << "\n";
		}
	}
}

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	int t = 10;
	cout << t << '\n';
	cout << "11\n"
			"1 1 1 1 1 1 1\n"
			"16\n"
			"1 1 h\n"
			"2 1 11\n"
			"2 2 11\n"
			"1 2 e\n"
			"1 3 l\n"
			"1 4 l\n"
			"1 5 l\n"
			"2 1 11\n"
			"1 6 o\n"
			"1 7 w\n"
			"2 2 11\n"
			"1 8 o\n"
			"1 9 r\n"
			"1 10 l\n"
			"1 11 d\n"
			"2 1 11\n";
	randomData(100, 100, 0.5);
	randomData(100, 100, 0.3);
	randomData(100, 100, 0.7);
	randomData(100, 100, 0.1);
	randomData(100, 100, 0.9);
	randomData(100, 100, 0.4);
	randomData(100, 100, 0.6);
	randomData(100, 100, 0.5);
	randomData(49000, 49000, 0.3);
	return 0;
}