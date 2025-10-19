#include <bits/stdc++.h>

using i64 = long long;

const int mod = 998244353;

long long quickpow(long long a, long long b) {
	long long res = 1;
	a %= mod;
	while (b) {
		if (b & 1)
			res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

void solve() {
	int n;
	std::cin >> n;
	i64 ans = (quickpow(2, n - 1) - 1 + mod) % mod;
	std::cout << ans << '\n';
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