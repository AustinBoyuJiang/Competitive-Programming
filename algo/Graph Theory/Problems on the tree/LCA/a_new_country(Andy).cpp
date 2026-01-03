// Author: Andy Zhu

#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename T> using vec = vector<T>;
template <typename T1, typename T2> using um = unordered_map<T1, T2>;
using vi = vec<int>;
using vpii = vec<pii>;
using vpll = vec<pll>;

const int N = 1e4 + 10;
template <typename T> inline T Find(T x, T f[N]) {return x == f[x] ? x : f[x] = Find(f[x], f);}
template <typename T> inline bool merge(T u, T v, T f[N]) {T fu = Find(u, f); T fv = Find(v, f); if(fu == fv) return false; f[fu] = fv; return true;}


int n, m, q, F[N], f[N][22];
bool reach[N][N], vis2[N];
vi province[N];
vpii e[N];
um <int, vpll> Map; // store province to province
map <pii, pii> key; // store the first city reached when travelling province
int d[N]; // store depth
ll dist[N], dist2[N];
int flydist[N][N];

// find whether city i can reach city j
void dfs1(int u, int vis[N], int start) {
    if(vis[u]) return;
    vis[u] = 1;
    reach[start][u] = true;
    for(pii v : e[u]) {
        dfs1(v.fir, vis, start);
    }
}

// find shortest dist in a city
void Floyd(int p) {
    for(int i = 0;i<N;i++) {
        flydist[i][0] = flydist[0][i] = 0;
    }
    for(int u : province[p]) {
        flydist[u][u] = 0;
        for(pii v : e[u]) {
            if(p == Find(v.fir, F)) flydist[u][v.fir] = v.sec;
        }
    }
    for(int k : province[p])
        for(int i : province[p])
            for(int j : province[p])
                flydist[i][j] = min(flydist[i][j], flydist[i][k] + flydist[k][j]);
}

// get f later for finding the LCA
void dfs2(int u, int fa, int dep, ll distance, ll distance2) {
    d[u] = dep;
    dist[u] = dist[fa] + distance;
    dist2[u] = dist[fa] + distance2;
    f[u][0] = fa;
    for(int i = 1;i<=20;i++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for(pii v : Map[u]) {
        if(v.fir == fa) continue;
        int x = key[mp(fa, u)].sec;
        int y = key[mp(u, v.fir)].fir;
        dfs2(v.fir, u, dep + 1, v.sec + flydist[x][y], v.sec + flydist[y][x]);
    }
}

// Find the two point to the LCA
pii LCA(int u, int v) {
    bool flag = false;
    if(d[u] < d[v]) {
        swap(u, v);
        flag = true;
    }
    for(int i = 20;i>=0;i--) {
        if(d[f[u][i]] > d[v]) u = f[u][i];
        if(f[u][0] == v) {
            if(flag) swap(u, v);
            return mp(u, v);
        }
    }

    // move them to the same level
    if(d[u] > d[v]) u = f[u][0];
    for(int i = 20;i>=0;i--) {
        if(f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }
    }
    if(flag) swap(u, v);
    return mp(u, v);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>q;
    for(int i = 1;i<=m;i++) {
        int u, v, w;
        cin>>u>>v>>w;
        e[u].pb(mp(v, w));
    }

    for(int i = 1;i<=n;i++) {
        int vis[N] = {0};
        dfs1(i, vis, i);
    }
    // group cities together with disjoint set
    for(int i = 1;i<=n;i++) F[i] = i;
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            if(reach[i][j] && reach[j][i]) merge(i, j, F);

    // Mark all provinces and build graph
    // Also get from which city to which city is which province to which province
    for(int u =1 ;u<=n;u++) {
        for(pii v : e[u]) {
            if(Find(u, F) != Find(v.fir, F)) {
                Map[Find(u, F)].pb(mp(Find(v.fir,F), v.sec));
                Map[Find(v.fir,F)].pb(mp(Find(u, F), v.sec));
                key[mp(Find(u, F), Find(v.fir,F))] = mp(u, v.fir);
                key[mp(Find(v.fir,F), Find(u, F))] = mp(v.fir, u);
            }
        }
    }

    // get floyd algorithm
    memset(flydist, 63, sizeof(flydist));
    for(int i = 1;i<=n;i++) {
        province[Find(i, F)].pb(i);
    }
    for(int i = 1;i<=n;i++) {
        if(!vis2[Find(i, F)]) Floyd(Find(i, F));
    }

    // get the difference array to calculate dist
    dfs2(Find(1, F), 0, 1, 0, 0);

    while(q--) {
        int u, v;
        cin>>u>>v;
        int pu = Find(u, F);
        int pv = Find(v, F);
        if(pu == pv) {
            cout<<flydist[u][v]<<"\n";
            continue;
        }
        pii sons = LCA(pu, pv);
        int& lc = sons.fir;
        int& rc = sons.sec;
        int& lca = d[pu] >= d[pv] ? f[lc][0] : f[rc][0];
        ll lclca = flydist[key[(mp(lca, lc))].fir][key[mp(f[lca][0], lca)].sec];
        ll lcarc = flydist[key[mp(f[lca][0], lca)].sec][key[mp(lca, rc)].fir];
        ll distu = pu == lca ? flydist[u][key[mp(pu, rc)].fir] : flydist[u][key[mp(pu, f[pu][0])].fir];
        ll distv = pv == lca ? flydist[key[mp(pv, lc)].fir][v] : flydist[key[mp(pv, f[pv][0])].fir][v];
        ll distlca = flydist[key[mp(lc, lca)].sec][key[mp(rc, lca)].sec];
        cout<<dist2[pu] + dist[pv] - (dist[lca] << 1) + distu + distv + distlca - lclca - lcarc <<"\n";
    }
    return 0;
}