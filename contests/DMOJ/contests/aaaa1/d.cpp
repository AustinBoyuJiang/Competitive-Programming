#pragma GCC optimize(2)
#include <bits/stdc++.h>
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
const int MOD = 1e9+7;

template<class T> inline bool chkmax(T &a, const T &b){ 
    if(b > a){ a = b; return true; } 
    return false; 
}

template<class T> inline bool chkmin(T &a, const T &b){ 
    if(b < a){ a = b; return true; } 
    return false; 
}

namespace combi {

    template<class T1, class T2>
    inline T1 qpow(T1 a, T2 b) {
        T1 ans = 1;
        for(; b; b >>= 1) {
            if (b & 1){
            	ans  = ans * 1LL * a % MOD;
            }
            a = a * 1LL * a % MOD;
        }
        return ans;
    }

    template<class T>
    inline T inv(T x) {
        return qpow(x, (T)(MOD - 2)); // MOD must be prime
    }

    inline vector<long long> fact{1}, invfact{1};

    inline void _ensure(int n) {
        if ((int)fact.size() > n) return;
        int old = (int)fact.size() - 1;
        fact.resize(n + 1);
        for (int i = old + 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;

        invfact.resize(n + 1);
        invfact[n] = inv(fact[n]);
        for (int i = n; i > old + 1; i--) invfact[i - 1] = invfact[i] * i % MOD;
    }

    inline long long C(int n, int k) {
        if (k < 0 || k > n) return 0;
        _ensure(n);
        return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
    }

    inline long long P(int n, int k) {
        if (k < 0 || k > n) return 0;
        _ensure(n);
        return fact[n] * invfact[n - k] % MOD;
    }

} using namespace combi;


const int N = 310;

int n,m,a[N][N],x[N*N],y[N*N];
int dp[N][N][N]; //dp[k][i][j]: the number of i x j matrixs that has the mex set of the first k values
int sum[N][N][N];

void SOLVE(int Case){
	cin>>n>>m;
	rep(i,1,n){
		rep(j,1,m){
			cin>>a[i][j];
			x[a[i][j]]=i;
			y[a[i][j]]=j;
		}
	}
	VI s;
	int l=INF,r=-INF,u=-INF,d=INF;
	rep(i,0,n*m-1){
		if(r<x[i]||l>x[i]||u<y[i]||d>y[i]){
			s.pb(i);
		}
		chkmin(l,x[i]);
		chkmax(r,x[i]);
		chkmax(u,y[i]);
		chkmin(d,y[i]);
	}
	s.pb(n*m);
	dp[1][1][1]=1;
	rep(i,1,n) rep(j,1,m){
		sum[1][i][j]=1;
	}
	_ensure(n*m);
	rep(k,2,(int)s.size()-1){
		rep(i,1,n) rep(j,1,m){
			if(i*j+1>s[k]){
				dp[k][i][j]+=2*j*(sum[k-1][i-1][j]-sum[k-1][i-1][j-1]+MOD)%MOD;
				dp[k][i][j]%=MOD;
				dp[k][i][j]+=2*i*(sum[k-1][i][j-1]-sum[k-1][i-1][j-1]+MOD)%MOD;
				dp[k][i][j]%=MOD;
				dp[k][i][j]+=4*sum[k-1][i-1][j-1]%MOD;
				dp[k][i][j]%=MOD;
				dp[k][i][j]*=fact[i*j-s[k-1]-1]*invfact[i*j-s[k]]%MOD;
				dp[k][i][j]%=MOD;
			}
			sum[k][i][j]=((dp[k][i][j]+sum[k][i-1][j]+sum[k][i][j-1]-sum[k][i-1][j-1])%MOD+MOD)%MOD;
		}
	}
	cout<<dp[(int)s.size()-1][n][m]<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("in.txt","r",stdin);
	//freopen("stdout.txt","w",stdout);
	int T=1;
	// cin>>T;
	for (int i = 1; i <= T; i++) SOLVE(i);
	return 0;
}