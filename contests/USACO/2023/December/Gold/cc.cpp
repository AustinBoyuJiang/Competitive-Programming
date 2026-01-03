#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define all(v) v.begin(), v.end()
#define fir first
#define sec second
#define lc (rt << 1)
#define rc (rt << 1 | 1)

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PI = pair<int,int>;
using PPI = pair<PI,int>;
using VI = vector<int>;
using VPI = vector<PI>;
template <class T> using Vec = vector<T>;
template <class T> using PQ = priority_queue<T>;
template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;

namespace Comfun{
	template<class T> inline T chkmax(T &a,T b){return a=max(a,b);}
	template<class T> inline T chkmin(T &a,T b){return a=min(a,b);}
} using namespace Comfun;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

const int N=2e5+10;

int n,q,p[N],sum[N],suml[N],sumr[N];

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n;
	rep(i,1,n){
		cin>>p[i];
	}
	sort(p+1,p+n+1);
	rep(i,1,n){
		sum[i]=sum[i-1]+p[i];
	}
	rep(i,1,n){
		suml[i]=p[i]*i-sum[i];
		sumr[i]=(sum[n]-sum[i])-p[i]*(n-i);
	}
	cin>>q; 
	rep(i,1,q){
		int a,b;
		cin>>a>>b;
		int ans=INF;
		rep(j,1,n){
			chkmin(ans,a*suml[j]+b*sumr[j]);
		}
		cout<<ans<<endl;
	}
	return 0;
}

