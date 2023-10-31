#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

const int mod = 1e9 + 7;

i64 quickpow(i64 a, i64 b) {
	i64 res = 1;
	a %= mod;
	while (b) {
		if (b & 1)
			res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

i64 inv(i64 n) {
	return quickpow(n, mod - 2);
}

struct mat {
	int a[11][11]{};

	int *operator[](int row) { return a[row]; }

	mat operator*(mat &y) {
		mat &x = *this;
		mat z;
		for (int i = 0; i < 11; ++i) {
			for (int j = i; j < 11; ++j) {
				u64 s = 0;
				for (int k = i; k <= j; ++k) {
					s += (u64) x[i][k] * y[k][j];
				}
				z[i][j] = s % mod;
			}
		}
		return z;
	}
};

mat getE() {
	mat x;
	for (int i = 0; i < 11; ++i) x[i][i] = 1;
	return x;
}

const mat E = getE();
mat A = E, B[7] = {E, E, E, E, E, E, E};

const int N = 5e4 + 5;

struct node {
	int l{}, r{};
	mat x{};
} tr[N << 2];

#define T tr[n]
#define LS tr[n<<1]
#define RS tr[n<<1|1]

void build(int n, int l, int r) {
	T.l = l, T.r = r;
	if (l == r) {
		T.x = A;
		return;
	}
	int m = (l + r) >> 1;
	build(n << 1, l, m);
	build(n << 1 | 1, m + 1, r);
	T.x = LS.x * RS.x;
}

void upd(int n, int x, int k) {
	if (T.l == T.r) {
		T.x = B[k];
		return;
	}
	int m = (T.l + T.r) >> 1;
	if (x <= m) upd(n << 1, x, k);
	else upd(n << 1 | 1, x, k);
	T.x = LS.x * RS.x;
}

mat qry(int n, int l, int r) {
	if (T.l >= l && T.r <= r) return T.x;
	if (T.l > r || T.r < l) return E;
	mat ls = qry(n << 1, l, r), rs = qry(n << 1 | 1, l, r);
	return ls * rs;
}

void solve() {
	int n;
	std::cin >> n;
	int p[7];
	i64 s = 0;
	for (int &i: p) {
		std::cin >> i;
		s += i;
	}
	for (int &i: p) {
		i = i * inv(s) % mod;
	}
	// h
	A[0][1] = p[0];
	B[0][0][1] = 1;
	// e
	A[1][2] = p[1];
	B[1][1][2] = 1;
	// l
	A[2][3] = A[3][4] = A[8][9] = p[2];
	B[2][2][3] = B[2][3][4] = B[2][8][9] = 1;
	// o
	A[4][5] = A[6][7] = p[3];
	B[3][4][5] = B[3][6][7] = 1;
	// w
	A[5][6] = p[4];
	B[4][5][6] = 1;
	// r
	A[7][8] = p[5];
	B[5][7][8] = 1;
	// d
	A[9][10] = p[6];
	B[6][9][10] = 1;
	std::map<char, int> mp;
	mp['h'] = 0;
	mp['e'] = 1;
	mp['l'] = 2;
	mp['o'] = 3;
	mp['w'] = 4;
	mp['r'] = 5;
	mp['d'] = 6;
	build(1, 1, n);
	int q;
	std::cin >> q;
	while (q--) {
		int o;
		std::cin >> o;
		if (o == 1) {
			int x;
			char c;
			std::cin >> x >> c;
			upd(1, x, mp[c]);
		} else {
			int l, r;
			std::cin >> l >> r;
			mat M = qry(1, l, r);
			std::cout << M[0][10] << '\n';
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}