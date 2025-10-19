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

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

const int N = 2e5+10;

int n,m,in[N],out[N],dp[N][2];
PI flag[N];
VPI e[N],to[N];

bool check(PI a,PI b,int cnt){
	if(a==b) return 1;
	if(a.sec<b.sec) return 1;
	if(a.sec>b.sec) return 0;
	if(cnt>=10){
		if(dp[a.fir][1]<=dp[b.fir][1]) return 1;
		else return 0;
	}
	return check(flag[a.fir],flag[b.fir],cnt+1);
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;
	rep(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].pb({v,w});
		to[v].pb({u,w});
		in[v]++;
		out[u]++;
	}
	queue<int> q;
	rep(i,1,n){
		dp[i][0]=0;
		dp[i][1]=0;
		if(!out[i]){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(PI edge:e[u]){
			int v=edge.fir;
			if(dp[v][0]+1>dp[u][0]||dp[v][0]+1==dp[u][0]&&check(edge,flag[u],0)){
				dp[u][0]=dp[v][0]+1;
				dp[u][1]=dp[v][1]+edge.sec;
				flag[u]=edge;
			}
		}
		for(PI edge:to[u]){
			int v=edge.fir;
			out[v]--;
			if(!out[v]) q.push(v);
		}
	}
	rep(i,1,n){
		cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
	}
	return 0;
}
