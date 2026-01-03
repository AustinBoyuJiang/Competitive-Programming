#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;
using ull = unsigned long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<pair<int,int>>;
template <class T> using PQ = priority_queue<T>;
template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;

const ull UINF = (ull)4e18 + (ull)5e17;
const char nl = '\n';
constexpr int dx[4] = {1,-1,0,0};
constexpr int dy[4] = {0,0,1,-1};

inline ull safe_add(ull a, ull b){
    __uint128_t z = (__uint128_t)a + (__uint128_t)b;
    if(z > (__uint128_t)UINF) return UINF;
    return (ull)z;
}
inline bool inb(int x,int y,int n,int m){ return 0<=x && x<n && 0<=y && y<m; }

int n,m;

void SOLVE(int Case){
    int T; if(!(cin>>T)) return;
    while(T--){
        cin>>n>>m;
        vector<string> g(n);
        rep(i,0,n-1) cin>>g[i];
        auto ok=[&](int x,int y){ return inb(x,y,n,m) && g[x][y]!='#'; };

        int bx=-1, by=-1;
        vector<ull> dist(1LL*n*m, UINF);
        PQG<pair<ull,int>> pq;

        rep(i,0,n-1) rep(j,0,m-1){
            if(g[i][j]=='B'){ bx=i; by=j; }
            if(g[i][j]=='A'){
                int id=i*m+j;
                if(dist[id]>1){
                    dist[id]=1;
                    pq.push({1,id});
                }
            }
        }
        if(bx==-1 || pq.empty()){ cout<<-1<<nl; continue; }

        while(!pq.empty()){
            auto [d,id]=pq.top(); pq.pop();
            if(d!=dist[id]) continue;
            int x=id/m, y=id%m;
            rep(k,0,3){
                int ux=x+dx[k], uy=y+dy[k];
                int wx=x-dx[k], wy=y-dy[k];
                if(!ok(ux,uy) || !ok(wx,wy)) continue;
                int v = ux*m+uy, w = wx*m+wy;
                if(dist[w]<UINF){
                    ull cand = safe_add(d, dist[w]);
                    if(cand < dist[v]){
                        dist[v]=cand;
                        pq.push({cand,v});
                    }
                }
                if(dist[v]<UINF){
                    ull cand2 = safe_add(d, dist[v]);
                    if(cand2 < dist[w]){
                        dist[w]=cand2;
                        pq.push({cand2,w});
                    }
                }
            }
            rep(k,0,3){
                int mx=x+dx[k], my=y+dy[k];
                if(!ok(mx,my)) continue;
                if(dist[mx*m+my]==UINF) continue;
                int ox=mx+dx[k], oy=my+dy[k];
                if(!ok(ox,oy)) continue;
                int oid = ox*m+oy, mid = mx*m+my;
                ull cand = safe_add(d, dist[mid]);
                if(cand < dist[oid]){
                    dist[oid]=cand;
                    pq.push({cand, oid});
                }
            }
        }

        ull ans = dist[bx*m+by];
        if(ans>=UINF) cout<<-1<<nl;
        else cout<<ans<<nl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    for (int i = 1; i <= T; i++) SOLVE(i);
    return 0;
}
