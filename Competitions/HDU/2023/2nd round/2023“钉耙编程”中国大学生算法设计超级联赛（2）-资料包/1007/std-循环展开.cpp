#include <bits/stdc++.h>

using i64 = int_fast64_t;
constexpr int N = 1005;
int a[N][N], sz[N];
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
    int __ = [] {
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

inline char gc()
{
    const int S = 1 << 22;
    static char buf[S], *s = buf, *t = buf;
    if (s == t) t = buf + fread(s = buf, 1, S, stdin);
    if (s == t) return EOF;
    return *s++;
}

int rd()
{
    int a = 0, b = 1, c = gc();
    for (; !isdigit(c); c = gc()) b ^= (c == '-');
    for (; isdigit(c); c = gc()) a = a * 10 + c - '0';
    return b ? a : -a;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    T = rd();
    while (T--)
    {
        int n, m;
        n = rd(), m = rd();
        for (int i = 1; i <= n; i++)
        {
            sz[i] = 0;
            for (int j = 1; j <= n; j++)
                a[i][j] = 0;
        }
        while (m--)
        {
            int u, v;
            u = rd(), v = rd();
            a[u][v] = a[v][u] = 1;
            sz[u]++, sz[v]++;
        }
        i64 ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
            {
                int cnt_i = sz[i];
                int cnt_j = sz[j];
                int cnt = 0;
                int num[12] = {0};
                auto &p = a[i], &q = a[j];
                int k;
                for (k = 1; k <= n - 12; k += 12)
                {
                    num[0] += p[k] & q[k];
                    num[1] += p[k + 1] & q[k + 1];
                    num[2] += p[k + 2] & q[k + 2];
                    num[3] += p[k + 3] & q[k + 3];
                    num[4] += p[k + 4] & q[k + 4];
                    num[5] += p[k + 5] & q[k + 5];
                    num[6] += p[k + 6] & q[k + 6];
                    num[7] += p[k + 7] & q[k + 7];
                    num[8] += p[k + 8] & q[k + 8];
                    num[9] += p[k + 9] & q[k + 9];
                    num[10] += p[k + 10] & q[k + 10];
                    num[11] += p[k + 11] & q[k + 11];
                }
                for (int x: num)
                    cnt += x;
                for (; k <= n; k++)
                    cnt += p[k] & q[k];
                if (a[i][j])
                    cnt_i--, cnt_j--;
                ans = (ans + C(cnt, 4) * C(cnt_i - 4, 2) + C(cnt, 4) * C(cnt_j - 4, 2)) % mod;
            }
        std::cout << ans << '\n';
    }
    return 0;
}