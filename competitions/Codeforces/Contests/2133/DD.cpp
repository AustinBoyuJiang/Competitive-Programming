#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define int long long
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

template<class T> inline bool chkmax(T &a, const T &b){ 
    if(b > a){ a = b; return true; } 
    return false; 
}

template<class T> inline bool chkmin(T &a, const T &b){ 
    if(b < a){ a = b; return true; } 
    return false; 
}

const int N = 1e6+10;

int n;

struct SegTree {
    int N;
    vector<long long> t;
    const long long NEG = -(1LL<<60);
    void init(int n){
        N = 1; while(N < n+2) N <<= 1;
        t.assign(2*N, NEG);
    }
    void update(int pos, long long val){
        int i = pos + N;
        t[i] = val;
        for(i >>= 1; i; i >>= 1) t[i] = max(t[i<<1], t[i<<1|1]);
    }
    long long query(int l, int r){
        if(l > r) return NEG;
        long long res = NEG;
        for(l += N, r += N; l <= r; l >>= 1, r >>= 1){
            if(l & 1) res = max(res, t[l++]);
            if(!(r & 1)) res = max(res, t[r--]);
        }
        return res;
    }
};

void SOLVE(int Case){
    cin>>n;
    vector<ll> h(n+1);
    ll sumH=0;
    rep(i,1,n){ cin>>h[i]; sumH+=h[i]; }
    const ll NEG = -(1LL<<60);
    vector<ll> dp(n+1, NEG);
    dp[1]=0;
    SegTree segB, segDP;
    segB.init(n+2);
    segDP.init(n+2);
    segB.update(1, dp[1]-1);
    segDP.update(1, dp[1]);
    ll bestExtra=0;
    rep(j,2,n){
        ll cap=h[j];
        int L1 = max(1, j - (int)cap);
        int R1 = j - 1;
        ll A = (L1<=R1)? (j + segB.query(L1,R1) - 2) : NEG;
        int R2 = j - (int)cap - 1;
        ll B = (R2>=1)? (segDP.query(1,R2) + cap - 2) : NEG;
        ll best = max(A,B);
        if(best > dp[j]) dp[j]=best;
        if(dp[j] >bestExtra) bestExtra = dp[j];
        if(dp[j]> NEG/2){
            segB.update(j, dp[j]-j);
            segDP.update(j, dp[j]);
        } else {
            segB.update(j, NEG);
            segDP.update(j, NEG);
        }
    }
    ll b = n - 1;
    ll extra = max(0ll, bestExtra);
    ll ans = sumH - (b + extra);
    cout<<ans<<nl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    cin>>T;
    for (int i = 1; i <= T; i++) SOLVE(i);
    return 0;
}
