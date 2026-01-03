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

template<class T> inline bool chkmax(T &a, const T &b){ 
    if(b > a){ a = b; return true; } 
    return false; 
}
template<class T> inline bool chkmin(T &a, const T &b){ 
    if(b < a){ a = b; return true; } 
    return false; 
}

const int N = 1000000 + 10;

int n,m,a[N],b[N],fs[N],fc[N],tg[N];
ll pf[N],fnc[N];
int q[N],du[N];

void SOLVE(int Case){
	cin>>n>>m;
	int mx=0;
	rep(i,1,n){
		cin>>a[i];
		if(a[i]>mx) mx=a[i];
	}
	rep(i,0,mx) fs[i]=0;
	rep(i,1,n) fs[a[i]]++;

	VI g;
	rep(i,0,mx) if(fs[i]>0) g.pb(fs[i]);
	int U=g.size();

	rep(i,1,n) fc[i]=0;
	rep(i,1,m){
		cin>>b[i];
		int x=b[i];
		if(x>=n) fc[n]++;
		else if(x>0) fc[x]++;
	}

	int s=0;
	per(i,n,1){
		s+=fc[i];
		tg[i]=s;
	}

	ll cur=0;
	pf[0]=0;
	rep(i,1,n){
		cur+=1ll*i*fc[i];
		pf[i]=cur;
	}
	rep(i,1,n){
		fnc[i]=pf[i-1]+1ll*i*tg[i];
	}

	VI pg(U+1,0);
	rep(i,0,U-1) pg[i+1]=pg[i]+g[i];

	auto R=[&](int K){
		if(K==0) return 0;
		return pg[U]-pg[U-K];
	};

	auto ok=[&](int K){
		if(K==0) return true;
		int L=U-K;
		int Rn=R(K);
		if(Rn==0) return true;

		ll ss=0;
		per(t,K,1){
			ss+=g[L+t-1];
			q[t]=ss;
		}

		rep(i,1,Rn+1) du[i]=0;
		rep(t,1,K){
			int x=q[t];
			if(x>0){
				du[1]++;
				if(x+1<=Rn) du[x+1]--;
			}
		}

		int c=0; ll S=0;
		rep(k,1,Rn){
			c+=du[k];
			S+=c;
			if(S>fnc[k]) return false;
		}
		return true;
	};

	int l=0,r=U,ans=0;
	while(l<=r){
		int md=(l+r)>>1;
		if(ok(md)){
			ans=md;
			l=md+1;
		}else r=md-1;
	}

	cout<<"Case #"<<Case<<": "<<R(ans)<<nl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; 
	cin>>T;
	rep(i,1,T) SOLVE(i);
	return 0;
}
