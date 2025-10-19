#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>
#define maxn 100010
#define maxm 1000010
#define INF 1000000000
#define lowbit(i) ((i) & (-i))
using namespace std;

#define lc T[i].ch[0]
#define rc T[i].ch[1]
struct SegmentTree1 {
  struct node {
    int v, ch[2];
  } T[maxn * 30]; int rt, top;
  void init() { T[rt = top = 0].v = INF; }

  inline void maintain(int i) { T[i].v = min(T[lc].v, T[rc].v); }

  void update(int &i, int l, int r, int k, int v) {
    if (!i) i = ++top, T[i] = { INF, 0, 0 };
    if (l == r) return T[i].v = min(T[i].v, v), void();
    int m = l + r >> 1;
    if (k <= m) update(lc, l, m, k, v);
    else update(rc, m + 1, r, k, v);
    maintain(i); 
  }

  int query(int i, int l, int r, int L, int R) {
    if (l > R || r < L || !i) return INF;
    if (L <= l && r <= R) return T[i].v;
    int m = l + r >> 1;
    return min(query(lc, l, m, L, R), query(rc, m + 1, r, L, R)); 
  }
} T[2], S;

int n, m, a[maxn], b[maxn], s[maxn];
int l[maxm], r[maxm];
int nxt[maxn][30];

int Bit[maxn];
void add(int i, int v) { while (i <= n) Bit[i] |= v, i += lowbit(i); }
int query(int i) {
  int s = 0; 
  while (i) s |= Bit[i], i -= lowbit(i);
  return s;
}

vector<pair<int, int>> Q[maxn];
int ans[maxm];

namespace calc_ans { 
  const int base = 233;
  const int p = 998244353;
  inline int add(int x, int y) { return (x += y) >= p ? x - p : x; } 
  inline int mul(int x, int y) { return 1ll * x * y % p; }

  int calc() {
    int res = 0, t = 1; 
    for (int i = 1; i <= m; ++i) {
      t = mul(t, base);
      res = add(res, mul(t, ans[i]));
    }
    return res;
  }
}

const int N = 1000000000;
void work() {
  cin >> n >> m; 
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    assert(a[i] <= 500000000);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i], s[i] = s[i - 1] + b[i];
    assert(b[i] <= 5000);
    assert(s[i] <= 500000000);
  }
  for (int o = 0; o < 30; ++o) {
    T[0].init(); T[1].init(); S.init();
    for (int i = n; i; --i) {
      int d = s[i] >> o & 1, v1 = s[i] & (1 << o) - 1, v2 = s[i] & (1 << o + 1) - 1;
      T[d].update(T[d].rt, 0, N, v1, i);
      S.update(S.rt, 0, N, v2, i);
      if (s[i] >= a[i]) {
        int d = s[i] - a[i] >> o & 1, v = s[i] - a[i] & (1 << o) - 1;
        nxt[i][o] = min(T[d].query(T[d].rt, 0, N, 0, v - 1), T[d ^ 1].query(T[d ^ 1].rt, 0, N, v, N));
      } else {
        int v = a[i] - s[i] & (1 << o + 1) - 1; 
        nxt[i][o] = min(S.query(S.rt, 0, N, (1 << o) - v, (1 << o + 1) - v - 1),
                        S.query(S.rt, 0, N, (1 << o) + (1 << o + 1) - v, N));
      }
    }
  }
  for (int i = 1; i <= n; ++i) Q[i].clear();
  for (int i = 1; i <= n; ++i) Bit[i] = 0; 
  for (int i = 1; i <= m; ++i) {
    int x, y; cin >> x >> y;
    l[i] = x, r[i] = y; 
    Q[x].emplace_back(y, i);
  }
  for (int i = n; i; --i) {
    for (int o = 0; o < 30; ++o) 
      if (nxt[i][o] != INF) add(nxt[i][o], 1 << o);
    for (auto [r, id] : Q[i]) ans[id] = query(r); 
  }
  //set<int> S;
  //for (int i = 0; i <= 30; ++i) S.insert((1 << i) - 1);
  /*for (int i = 1; i <= m; ++i) {
    if (S.find(ans[i]) == S.end()) std::cout << r[i] - l[i] + 1 << " " << ans[i] << "\n";
    //cout << ans[i] << "\n";
    }*/
  cout << calc_ans::calc() << "\n";
}

int main() { 
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int T = 0; cin >> T; 
  while (T--) work(); 
  return 0;
}
