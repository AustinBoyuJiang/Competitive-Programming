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
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<pair<int,int>>;
template <class T> using PQ = priority_queue<T>; 
template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;

const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const char nl = '\n';
constexpr array<pair<int,int>,8> dir = {{
    {1,0}, {0,1}, {0,-1}, {-1,0},
    {1,1}, {1,-1}, {-1,1}, {-1,-1}
}};
const int MOD = 998244353;

template<class T> inline bool chkmax(T &a, const T &b){ if(b>a){ a=b; return true; } return false; }
template<class T> inline bool chkmin(T &a, const T &b){ if(b<a){ a=b; return true; } return false; }

const int N = 1e6+10;

int n,k,m;

struct U {
    vector<int> p;
    void init(int n){ p.resize(n+2); rep(i,0,n+1) p[i]=i; }
    int f(int x){
        while(p[x]!=x){ p[x]=p[p[x]]; x=p[x]; }
        return x;
    }
    void del(int x){ p[x]=f(x+1); }
};

void SOLVE(int Case){
    cin>>n>>k>>m;
    vector<VI> r(m);
    vector<U> d(m);
    vector<VPI> pos(n+1);
    rep(i,0,m-1){
        int L; cin>>L;
        r[i].resize(L+1);
        rep(j,1,L){
        	cin>>r[i][j];
        	pos[r[i][j]].pb({i,j});
        	}
        d[i].init((int)r[i].size());
    }
    vector<int> dist(n+1,-1);
    queue<int> q;
    dist[1]=0; q.push(1);
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(auto &e: pos[u]){
            int id=e.F, p=e.S;
            int L=(int)r[id].size()-1;
            int lim=min(L,p+k);
            int x=d[id].f(p+1);
            while(x<=lim){
                int v=r[id][x];
                if(dist[v]==-1){ dist[v]=dist[u]+1; q.push(v); }
                d[id].del(x);
                x=d[id].f(x);
            }
        }
    }
    ll ans=0;
    rep(i,1,n){
        if(dist[i]==-1) ans+=1ll*i*(-1);
        else ans+=1ll*i*dist[i];
    }
    cout<<"Case #"<<Case<<": "<<ans<<nl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; cin>>T;
    rep(i,1,T) SOLVE(i);
    return 0;
}
