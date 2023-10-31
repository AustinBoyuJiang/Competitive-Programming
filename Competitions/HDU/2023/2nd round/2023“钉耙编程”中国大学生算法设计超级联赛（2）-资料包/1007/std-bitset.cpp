#include <bits/stdc++.h>

using i64 = int64_t;
constexpr int N = 1005;
std::bitset<N> bt[N];
constexpr i64 mod = 1e9 + 7;

i64 fpow(i64 x, i64 r)
{
    i64 result = 1;
    while (r)
    {
        if (r & 1)result = result * x % mod;
        r >>= 1;
        x = x * x % mod;
    }
    return result;
}

namespace binom {
    i64 fac[N], ifac[N];
    int __ = []
    {
        fac[0] = 1;
        for (int i = 1; i <= N - 5; i++)
            fac[i] = fac[i - 1] * i % mod;
        ifac[N - 5] = fpow(fac[N - 5], mod - 2);
        for (int i = N - 5; i; i--)
            ifac[i - 1] = ifac[i] * i % mod;
        return 0;
    }();

    inline i64 C(int n, int m)
    {
        if (n < m || m < 0)return 0;
        return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
    }

    inline i64 A(int n, int m)
    {
        if (n < m || m < 0)return 0;
        return fac[n] * ifac[n - m] % mod;
    }
}
using namespace binom;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while (T--)
    {
        int n, m;
        std::cin >> n >> m;
        for (int i = 1; i <= n; i++)
            bt[i].reset();
        while (m--)
        {
            int u, v;
            std::cin >> u >> v;
            bt[u][v] = bt[v][u] = 1;
        }
        i64 ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
            {
                int cnt_i = bt[i].count();
                int cnt_j = bt[j].count();
                int cnt = (bt[i] & bt[j]).count();
                if (bt[i][j])
                    cnt_i--, cnt_j--;
                ans = (ans + C(cnt, 4) * C(cnt_i - 4, 2) + C(cnt, 4) * C(cnt_j - 4, 2)) % mod;
            }
        std::cout << ans << '\n';
    }
    return 0;
}