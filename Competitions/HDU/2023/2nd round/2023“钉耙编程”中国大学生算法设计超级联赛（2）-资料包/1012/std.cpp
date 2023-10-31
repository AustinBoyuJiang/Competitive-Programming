#include <bits/stdc++.h>
#define N 30000
#define S (N*2+1)
#define T (N*2+2)
#define INF 0x7FFFFFFF
#define rep(i, l, r) for (int i = (l); i <= (r); ++(i))
#define cmax(a,b) a=max(a,b)
#define cmin(a,b) a=min(a,b)
using namespace std;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-')f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

struct edge {int nex, t, w;} e[500010];
int h[N*2 + 10], tot, d[N*2 + 10], q[N*2 + 10], qn, c[N*2 + 10];
int a[N + 5], p[N + 5], pn;
inline void Link(int x, int y, int w, int W = 0) {
	e[++tot] = (edge) {h[x], y, w}; h[x] = tot;
	e[++tot] = (edge) {h[y], x, W}; h[y] = tot;
}
bool bfs() {
	memset(d, 0, sizeof(d)); int i, j;
	for (d[q[i = qn = 0] = S] = 1; i <= qn; ++i)for (j = c[q[i]] = h[q[i]]; j; j = e[j].nex)
			if (e[j].w && !d[e[j].t])d[q[++qn] = e[j].t] = d[q[i]] + 1;
	return d[T];
}
int dfs(int x, int r) {
	if (x == T)return r;
	int k, u = 0;
	for (int&i = c[x]; i; i = e[i].nex)if (e[i].w && d[e[i].t] == d[x] + 1) {
			k = dfs(e[i].t, r - u < e[i].w ? r - u : e[i].w);
			u += k; e[i].w -= k; e[i ^ 1].w += k;
			if (u == r)return u;
		}
	return d[x] = 0, u;
}

void solve(){
	int n = read(), m = read(), k = read();
	rep(i,1,n)a[i] = read();
	memset(p, pn = 0, sizeof(p));
	memset(h, 0, sizeof(h)); tot = 1;
	rep(i,1,m) {
		int x = read(), y = read();
		p[x] ? Link(p[x], ++pn, a[x]) : Link(S, ++pn, 1); p[x] = pn;
		p[y] ? Link(p[y], ++pn, a[y]) : Link(S, ++pn, 1); p[y] = pn;
		Link(p[x], p[y], 1, 1);
	}
	for (int i = 1; i <= k; ++i) {
		int x = read();
		if (!p[x])Link(S, T, 1);
		else Link(p[x], T, a[x]);
	}
	int x;
	for (x = 0; bfs();)x += dfs(S, INF);
	printf("%d\n", x);
}

int main() {
	int t = read();
	while(t--)solve();
}
