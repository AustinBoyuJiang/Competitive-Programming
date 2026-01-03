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

int n,m,a[N],b[N];

void SOLVE(int Case){
	cin>>n>>m;
	int mn1=LLINF,mx1=-LLINF;
	rep(i,1,n){
		cin>>a[i];
		chkmin(mn1,a[i]);
		chkmax(mx1,a[i]);
	}
	sort(a+1,a+n+1);
	int mn2=LLINF,mx2=-LLINF;
	rep(i,1,m){
		cin>>b[i];
		chkmin(mn2,b[i]);
		chkmax(mx2,b[i]);
	}
	sort(b+1,b+m+1);
	ll ans=0;
	if(mn2<mn1) ans+=mn1-mn2;
	if(mx2>mx1) ans+=mx2-mx1;
	int l=1,r=0;
	rep(i,2,n){
		while(r<m&&b[r+1]<a[i]) r++;
		while(l<=m&&b[l]<=a[i-1]) l++;
		if(l>r) continue;
		int g=max(b[l]-a[i-1]-1,a[i]-b[r]-1);
		rep(j,l+1,r){
			chkmax(g,b[j]-b[j-1]-1);
		}
		ans+=a[i]-a[i-1]-1-g;
 	}
 	cout<<ans<<endl;
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