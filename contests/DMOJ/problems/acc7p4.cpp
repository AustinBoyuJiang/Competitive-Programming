#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'
#define fir first
#define sec second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<PI>;
template <class T> using PQ = priority_queue<T>; 
template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;

const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int dir[8][2] = {
    {1,0},{0,1},{0,-1},{-1,0},
    {1,1},{1,-1},{-1,1},{-1,-1}
};
const int MOD = 998244353;

template<class T> bool chkmax(T &a, const T &b){ 
    if(b > a){ a = b; return true; } 
    return false; 
}

template<class T> bool chkmin(T &a, const T &b){ 
    if(b < a){ a = b; return true; } 
    return false; 
}

namespace combi {

    template<class T>
    inline T qpow(T a, T b) {
        T ans = 1;
        while (b) {
            if (b & 1) { ans = (ans * a) % MOD; }
            a = (a * a) % MOD;
            b >>= 1;
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

const int N = 1e5+10;

int k,p0[N],in[N];
ll n;

int get(int k){
	if(k==0) return 0;
	return k*1ll*p0[k-1]%MOD;
}

void SOLVE(int Case){
	cin>>n>>k;
	p0[1]=1;
	if(n==1) p0[0]=1;
	else p0[0]=0;
	for (int i = 2; i < k; i++) in[i] = i; // inv暂时当底数
	for (int i = 1; i < k; i++) p0[i] = 1;  // p0最终会是i^n
	
	for (int nn = (n-1)%(MOD-1); nn; nn >>=1) {
	    if (nn & 1) {
	        for (int i = 2; i < k; i++)
	            p0[i] = (p0[i] * 1LL * in[i]) % MOD;
	    }
	    if (nn > 1) {
	        for (int i = 2; i < k; i++)
	            in[i] = (in[i] * 1LL * in[i]) % MOD;
	    }
	}
	// cout<<p0[0]<<" "<<qpow(0ll,n-1)<<endl;
	// cout<<p0[1]<<" "<<qpow(1ll,n-1)<<endl;
	// cout<<p0[2]<<" "<<qpow(2ll,n-1)<<endl;
	int ans=0;
	int dir=1;
	per(i,k,0){
		ans+=C(k,i)*1ll*get(i)%MOD*dir;
		ans=(ans%MOD+MOD)%MOD;
		dir*=-1;
	}
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));
	int T=1;
	// cin>>T;
	rep(i,1,T){
		SOLVE(i);
	}
	return 0;
}