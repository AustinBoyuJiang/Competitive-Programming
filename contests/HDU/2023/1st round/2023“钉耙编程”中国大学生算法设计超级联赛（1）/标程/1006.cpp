// #pragma comment(linker, "/STACK:1024000000,1024000000") 
#include <bits/stdc++.h>
 
using namespace std;
using i64 = long long;
 
const int N = 100000 + 5;
const int MAXN = N * 100;
 
const i64 R = 1e10;
 
vector<pair<int , int>> G[N];
 
i64 L , f[N] , sum[N];
 
struct Line {
	i64 k , b;
} LINE[N];
 
int lson[MAXN] , rson[MAXN] , idL[MAXN];
int root[N];
 
int cnt = 0;
 
#define mid (((l) + (r)) >> 1)
 
i64 calc(int id , i64 x) {
	return LINE[id].k * x + LINE[id].b;
}
 
void insert(int &rt , i64 l , i64 r , int id) {
	if (rt == 0) {
		rt = ++cnt;
		idL[rt] = id;
		return ;
	}
	if (calc(idL[rt] , mid) > calc(id , mid)) {
		swap(idL[rt] , id);
	}
	if (calc(idL[rt] , l) <= calc(id , l) && calc(idL[rt] , r) <= calc(id , r)) {
		return ;
	}
	if (calc(idL[rt] , l) > calc(id , l)) {
		insert(lson[rt] , l , mid , id);
	} else {
		insert(rson[rt] , mid + 1 , r , id);
	}
}
 
i64 query(int rt , i64 l , i64 r , i64 x) {
	assert(x >= -R && x <= R);
	if (rt == 0) {
		return INT64_MAX;
	}
	i64 ret = calc(idL[rt] , x);
	if (x <= mid) {
		ret = min(ret , query(lson[rt] , l , mid , x));
	} else {
		ret = min(ret , query(rson[rt] , mid + 1 , r , x));
	}
	return ret;
}
 
int merge(int u , int v , i64 l , i64 r) {
	if (!u || !v) {
		return u + v;
	}
	insert(u , l , r , idL[v]);
	lson[u] = merge(lson[u] , lson[v] , l , mid);
	rson[u] = merge(rson[u] , rson[v] , mid + 1 , r);
	return u;
}
 
void dfs(int u , int fa) {
	// cout << u << endl;
	assert(fabs(sum[u]) <= 100000000);
	int son = 0;
	for (auto [v , w] : G[u]) {
		if (v == fa) {
			continue;
		}
		sum[v] = sum[u] + w;
		dfs(v , u);
		root[u] = merge(root[u] , root[v] , -R , R);
		son++;
	}
	if (son == 0) {
		f[u] = 0;
	} else {
		f[u] = query(root[u] , -R , R , sum[u]) + sum[u] * sum[u] + L * L;
	}
	LINE[u] = {-2ll * sum[u] + 2ll * L, sum[u] * sum[u] - 2ll * sum[u] * L + f[u]};
	insert(root[u] , -R , R , u);
}
 
int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
 
	int T;
	cin >> T;
 
	while (T--) {
		// cerr << T << endl;;
		int n;
		cin >> n >> L;
 
		for (int i = 1 ; i <= n ; i++) {
			G[i].clear();
			G[i].shrink_to_fit();
		}
 
		for (int i = 1 ; i < n ; i++) {
			int u , v , w;
			cin >> u >> v >> w;
			G[u].push_back({v , w});
			G[v].push_back({u , w});
		}
 
		int q;
		cin >> q;
 
		while (q--) {
			int u;
			cin >> u;
			sum[u] = 0;
 
			for (int i = 1 ; i <= n ; i++) {
				root[i] = 0;
			}
			for (int i = 1 ; i <= cnt ; i++) {
				lson[i] = rson[i] = idL[i] = 0;
			}
			cnt = 0;
			// cerr << "T" << q << endl;
			// cerr << u << ",cnt=" << cnt << endl;
			dfs(u , 0);
			cout << f[u] << '\n';
		}
 
	}
	return 0;
}
/*
1
4 2
1 2 5
1 3 -4
1 4 6
4
1
2
3
4
*/
