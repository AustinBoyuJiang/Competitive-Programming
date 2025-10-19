#include <bits/stdc++.h>
 
using namespace std;
using i64 = long long;
 
template<int MOD>
struct ModInt {
    int x;
 
    ModInt() : x(0) {}
    ModInt(i64 y) : x(y >= 0 ? y % MOD : (MOD - (-y) % MOD) % MOD) {}
 
    inline int inc(const int &x) {
        return x >= MOD ? x - MOD : x;
    }
    inline int dec(const int &x) {
        return x < 0 ? x + MOD : x;
    }
 
    ModInt &operator+= (const ModInt &p) {
        x = inc(x + p.x);
        return *this;
    } 
    ModInt &operator-= (const ModInt &p) {
        x = dec(x - p.x);
        return *this;
    }
 
    ModInt &operator*= (const ModInt &p) {
        x = (int)(1ll * x * p.x % MOD);
        return *this;
    }
    ModInt &operator/= (const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }
 
    ModInt operator-() const { return ModInt(-x); } 
 
    friend ModInt operator + (const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) += rhs;
    }
    friend ModInt operator - (const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) -= rhs;
    }
    friend ModInt operator * (const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) *= rhs;
    }
    friend ModInt operator / (const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) /= rhs;
    }
 
    bool operator == (const ModInt &p) const { return x == p.x; } 
    bool operator != (const ModInt &p) const { return x != p.x; }
 
    ModInt inverse() const {
        int a = x, b = MOD, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }
 
    ModInt pow(i64 n) const {
        ModInt ret(1), mul(x);
        while(n > 0) {
            if(n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
 
    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }
 
    friend istream &operator>>(istream &is, ModInt &a) {
        i64 t;
        is >> t;
        a = ModInt<MOD>(t);
        return (is);
    }
    static int get_mod() { return MOD; }
};
 
const int MOD = 998244353;
using MInt = ModInt<MOD>;
 
inline int add(int x, int y) {
    return x + y >= MOD ? x + y - MOD : x + y;
}
 
inline void addx(int &x, int y) {
    x = add(x , y);
}
 
inline int sub(int x, int y) {
    return x - y < 0 ? x - y + MOD : x - y;
}
 
inline void subx(int &x, int y) {
    x = sub(x , y);
}
 
inline int mul(int x, int y) { return 1ull * x * y % MOD; }
 
inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}
 
vector <int> roots, rev;
 
void getRevRoot(int base) {
    int n = 1 << base;
    if ((int)roots.size() == n) return;
    roots.resize(n); rev.resize(n);
    for (int i = 1; i < n; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (base - 1));
    for (int mid = 1; mid < n; mid <<= 1) {
        int wn = fpow(3, (MOD - 1) / (mid << 1));
        roots[mid] = 1;
        for (int i = 1; i < mid; i++) roots[i + mid] = mul(roots[i + mid - 1], wn);
    }
}
 
void ntt(vector <int> &a, int base) {
    int n = 1 << base;
    for (int i = 0; i < n; i++) {
        if (i < rev[i]) {
            swap(a[i], a[rev[i]]);
        }
    }
    for (int mid = 1; mid < n; mid <<= 1) {
        for (int i = 0; i < n; i += (mid << 1)) {
            for (int j = 0; j < mid; j++) {
                int x = a[i + j], y = mul(a[i + j + mid], roots[mid + j]);
                a[i + j] = add(x, y); a[i + j + mid] = sub(x, y);
            }
        }
    }
}
 
const i64 P = 1ll * MOD * MOD;
const int N = 1001 * 1001 + 5, M = 22, U = 1005;
 
vector <int> F[M], G[M], tmp, ANS;
int n[M], facn[M], nt[N];
map<vector<int> , int> suf , ways;
int lim, k, dis;
 
vector<int> da;
void dfs1(int u) {
    if (u == k + 1) {
        int id = 0;
        for (int i = 1; i <= k; i++) id += da[i] * facn[i - 1];
            // cout << id << endl;
        int flag = 1;
        for (int i = 1 ; i <= k ; i++) {
            flag &= da[i] == 0;
        }
        if (flag == 1) tmp[id] = 1;
        else {
            if (suf.count(da)) tmp[id] = MOD - suf[da];
        }
        return;
    }
    for (int i = 0; i < n[u]; i++) {
        da[u] = i;
        dfs1(u + 1);
    }
}
 
void dfs2(int u) {
    if (u == k + 1) {
        int id = 0;
        for (int i = 1; i <= k; i++) id += da[i] * facn[i - 1];
        ways[da] = ANS[id];
        return;
    }
    for (int i = 0; i < n[u]; i++) {
        da[u] = i;
        dfs2(u + 1);
    }
}
 
vector <int> mul(vector <int> a, vector <int> b, int need, int ntted = 0, int limit = 0) {
    int len = (int)a.size() + (int)b.size() - 1, base = 0;
    if (limit) len = limit;
    while ((1 << base) < len) ++base;
    getRevRoot(base);
    for (int i = 0; i < k; i++) {
        F[i].clear(); F[i].resize(1 << base);
        if (!ntted) {
            G[i].clear(); G[i].resize(1 << base);
        }
    }
    for (int i = 0; i < (int)a.size(); i++) F[nt[i]][i] = a[i];
    if (!ntted) {
        for (int i = 0; i < (int)b.size(); i++) G[nt[i]][i] = b[i];
    }
    for (int i = 0; i < k; i++) {
        ntt(F[i], base);
        if (!ntted) ntt(G[i], base);
    }
    for (int i = 0; i < (1 << base); i++) {
        static i64 res[M];
        memset(res, 0, sizeof(res));
        for (int j = 0; j < k; j++) {
            for (int t = 0; t < k; t++) {
                int go = (j + t >= k ? j + t - k : j + t); 
                res[go] += 1ll * F[j][i] * G[t][i];
                if (res[go] >= P) res[go] -= P;
            }
        }
        for (int j = 0; j < k; j++) F[j][i] = res[j] % MOD;
    }
    int inv = fpow(1 << base, MOD - 2);
    for (int i = 0; i < k; i++) {
        ntt(F[i], base);
        reverse(F[i].begin() + 1, F[i].end());
    }
    vector <int> ans(need);
    for (int i = 0; i < need; i++) ans[i] = mul(inv, F[nt[i]][i]);
    return ans;
}
 
vector <int> pinv(vector <int> a, int n) {
    a.resize(n);
    if (n == 1) {
        vector <int> ans(1, fpow(a[0], MOD - 2));
        return ans;
    }
    vector <int> f0 = pinv(a, (n + 1) >> 1);
    vector <int> tmp = mul(a, f0, n, 0, n), ans = f0;
    for (int i = 0; i < (int)f0.size(); i++) tmp[i] = 0;
    tmp = mul(tmp, f0, n, 1, n); ans.resize(n);
    for (int i = (int)f0.size(); i < n; i++) ans[i] = sub(0, tmp[i]);
    return ans;
}
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int T;
    cin >> T;
 
    while (T--)
    {
        cin >> k;
        for (int i = 1 ; i <= k ; i++) {
            cin >> n[i];
            n[i]++;
        }
        int _ , __;
        cin >> _ >> __;
        suf.clear() , ways.clear();
        while(_--){
            vector<int> d(k + 1);
            for (int i = 1 ; i <= k ; i++) {
                cin >> d[i];
            }
            suf[d]++;
        }
        facn[0] = 1;
        for (int i = 1; i <= k; i++) facn[i] = facn[i - 1] * n[i];
        lim = facn[k];
        tmp.clear() , tmp.resize(lim);
        da.clear() , da.resize(k + 1);
        dfs1(1);
        for (int i = 0; i < lim; i++) {
            int res = 0;
            for (int j = 1; j < k; j++) res += i / facn[j];
            nt[i] = res % k;
        }
        ANS = pinv(tmp, lim);
        dfs2(1);
        vector<MInt> f(__ + 1);
        vector<vector<int>> v(__ + 1);
 
 
        v[0] = vector<int>(k + 1);
 
        for (int i = 1 ; i <= k ; i++) {
            v[0][i] = ::n[i] - 1;
        }
        for(int i = 1 ; i <= __ ; i++) {
            v[i] = vector<int>(k + 1);
            for (int j = 1 ; j <= k ; j++) {
                cin >> v[i][j];
            }
        }
 
        sort(v.begin() , v.end());
 
        auto check = [&](vector<int> a , vector<int> b) {
            int flag = 1;
            for (int i = 1 ; i <= k ; i++) {
                flag &= a[i] <= b[i];
            }
            return flag;
        };
 
        auto sub = [&](vector<int> a , vector<int> b) {
            auto ret = a;
            for (int i = 1 ; i <= k ; i++) {
                ret[i] -= b[i];
            }
            return ret;
        };
 
        for(int i = 0 ; i <= __ ; i++){
            f[i] = ways[v[i]];
            for(int j = 0 ; j < i ; j++) {
                if(check(v[j] , v[i])) {
                    f[i] -= f[j] * ways[sub(v[i] , v[j])];
                }
            }
        }
        cout << f[__] << '\n';
    }
}
