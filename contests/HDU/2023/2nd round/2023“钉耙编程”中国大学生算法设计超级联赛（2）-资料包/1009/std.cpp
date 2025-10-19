#include <bits/stdc++.h>
#include <cstdio>
#define N 2000010
#define rep(i, l, r) for (int i = (l); i <= (r); ++(i))
#define cmax(a, b) a = max(a, b)
#define cmin(a, b) a = min(a, b)
using namespace std;

char s[N];

void solve() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  vector<pair<char, int>> v;
  v.push_back({s[1], 1});
  rep(i, 2, n) {
    if (s[i] == v.back().first)
      ++v.back().second;
    else
      v.push_back({s[i], 1});
  }
  int ans = 0;
  for (auto [x, y] : v)
    ans += y - 1;
  printf("%d\n", ans);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}