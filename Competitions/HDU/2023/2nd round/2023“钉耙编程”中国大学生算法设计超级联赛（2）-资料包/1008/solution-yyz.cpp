#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 5e4 + 5, mod = 1e9 + 7;
const int helowrd[] = {'h', 'e', 'l', 'o', 'w', 'r', 'd'};
vector<int> pos[200];

ll qpow(ll a, ll b) {
    ll s = 1;
    while (b) {
        if (b & 1) s = s * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return s;
}

int n, q;
ll pro[200];

struct mat {
    static const int n = 11;
    ll a[n][n];

    ll *operator [](int i) { return a[i]; }

    void clear() {
        memset(a, 0, sizeof a);
    }

    void identity() { // 单位矩阵
        clear();
        for (int i = 0; i < n; ++i) {
            a[i][i] = 1;
        }
    }

    void init() { // 随机字母的转移矩阵
        identity();
        for (int c: helowrd) {
            for (int i: pos[c]) {
                a[i][i - 1] = pro[c];
            }
        }
    }

    mat operator *(const mat &b) const {
        mat c;
        c.identity();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                ull s = 0;
                for (int k = j; k <= i; ++k) {
                    s += a[i][k] * b.a[k][j];
                }
                c[i][j] = s % mod;
            }
        }
        return c;
    }
};

mat t[N << 2];

void work() {
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < 7; ++i) {
        cin >> pro[helowrd[i]];
        sum += pro[helowrd[i]];
    }
    ll inv_sum = qpow(sum, mod - 2);
    for (int i = 0; i < 7; ++i) {
        pro[helowrd[i]] = pro[helowrd[i]] * inv_sum % mod;
    }
    int N = 1;
    while (N < n + 2) N <<= 1;
    for (int i = 1; i <= n; ++i) t[N + i].init();
    for (int i = N - 1; i; --i) {
        t[i] = t[i << 1 | 1] * t[i << 1];
    }
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int idx;
            char c;
            cin >> idx >> c;
            t[N + idx].identity();
            for (int i: pos[c]) {
                t[N + idx][i][i - 1] = 1;
            }
            for (int i = N + idx >> 1; i; i >>= 1) {
                t[i] = t[i << 1 | 1] * t[i << 1];
            }
        }
        else {
            int l, r;
            cin >> l >> r;
            mat A, B;
            A.identity();
            B.identity();
            for (int i = N + l - 1, j = N + r + 1; i ^ j ^ 1; i >>= 1, j >>= 1) {
                if (~i & 1) A = t[i ^ 1] * A;
                if (j & 1) B = B * t[j ^ 1];
            }
            A = B * A;
            ll ans = A[10][0];
            ans = (ans % mod + mod) % mod;
            cout << ans << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    pos['h'] = {1};
    pos['e'] = {2};
    pos['l'] = {3, 4, 9};
    pos['o'] = {5, 7};
    pos['w'] = {6};
    pos['r'] = {8};
    pos['d'] = {10};
    int T;
    cin >> T;
    while (T--) {
        work();
    }
}