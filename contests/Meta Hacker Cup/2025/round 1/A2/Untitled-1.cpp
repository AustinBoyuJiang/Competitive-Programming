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

const int N = 5e5+10;

int n,a[N],f[N];

struct edge{
	int u,v,w;
};

vector<edge> e;

int root(int x){
	if(f[x]==x) return x;
	return f[x]=root(f[x]);
}

void merge(int x,int y){
	f[root(x)]=root(y);
	root(x);
	root(y);
	root(root(x));
	root(root(y));
}

void SOLVE(int Case){
	cin>>n;
	e.clear();
	f[0]=0;
	rep(i,1,n){
		f[i]=i;
		cin>>a[i];
		e.pb({0,i,a[i]});
	}
	rep(i,1,n-1){
		e.pb({i,i+1,abs(a[i]-a[i+1])});
	}
	sort(all(e),[](edge a,edge b){
		return a.w<b.w;
	});
	int ans=0;
	for(auto ee:e){
		if(root(ee.u)!=root(ee.v)){
			merge(ee.u,ee.v);
			chkmax(ans,ee.w);
		}
	}
	cout<<"Case #"<<Case<<": "<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	cin>>T;
	for (int i = 1; i <= T; i++) SOLVE(i);
	return 0;
}