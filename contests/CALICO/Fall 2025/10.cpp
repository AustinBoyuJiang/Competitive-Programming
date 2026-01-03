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

int n,m,cnt[N],vis[N];
VI e[N];

void dfs(int u){
	if(vis[u]) return;
	vis[u]=1;
	for(int v:e[u]){
		dfs(v);
	}
}

void SOLVE(int Case){
	cin>>n>>m;
	rep(i,1,n){
		e[i].clear();
		cnt[i]=0;
		vis[i]=0;
	}
	rep(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].pb(v);
		e[v].pb(v);
		cnt[u]-=w;
		cnt[v]+=w;
	}
	int ans=0;
	rep(i,1,n){
		ans+=max(cnt[i],0ll);
		if(cnt[i]>0) dfs(i);
	}
	rep(i,1,n){
		if(vis[i]) continue;
		if(cnt[i]==0){
			if(e[i].size()==0){
				continue;
			}
			dfs(i);
			ans++;
		}
	}
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("in.txt","r",stdin);
	//freopen("stdout.txt","w",stdout);
	int T=1;
	cin>>T;
	for (int i = 1; i <= T; i++) SOLVE(i);
	return 0;
}