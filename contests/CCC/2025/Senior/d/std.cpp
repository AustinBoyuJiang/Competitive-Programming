#pragma GCC optimize(2)

#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'

#define fir first
#define sec second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<PI>;
template <class T> using Vec = vector<T>;
template <class T> using PQ = priority_queue<T>; 
template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;

template<class T> inline T chkmax(T &a,T b){return a=max(a,b);}
template<class T> inline T chkmin(T &a,T b){return a=min(a,b);}

const int INF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e6+10;

int n,m,t[N],dist[N],vis[N];
Vec<PI> e[N];
VI ee[N];
VI tp[N],tt[N];

int tot;
map<PI,int> flag;

int id(int x,int y){
	if(flag[{x,y}]==0) flag[{x,y}]=++tot;
	return flag[{x,y}];
}

signed main(){
	cin>>n>>m;
	t[m+1]=0;
	tp[1].pb(m+1);
	rep(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		t[i]=w;
		ee[u].pb(v);
		ee[v].pb(u);
		tp[u].pb(i);
		tp[v].pb(i);
		e[id(u,i)].pb({id(v,i),0});
		e[id(v,i)].pb({id(u,i),0});
	}
	rep(u,1,n){
		sort(tp[u].begin(),tp[u].end(),[](int a,int b){
			return t[a]<t[b];
		});
		rep(i,1,(int)tp[u].size()-1){
			e[id(u,tp[u][i])].pb({id(u,tp[u][i-1]),t[tp[u][i]]-t[tp[u][i-1]]});
			e[id(u,tp[u][i-1])].pb({id(u,tp[u][i]),t[tp[u][i]]-t[tp[u][i-1]]});
		}
	}
	memset(dist,0x3f,sizeof(dist));
	dist[id(1,m+1)]=0;
	PQG<PI> q;
	q.push({0,id(1,m+1)});
	while(!q.empty()){
		PI tp=q.top();
		q.pop();
		int u=tp.sec;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto edge:e[u]){
			int v=edge.fir;
			int w=edge.sec;
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				q.push({dist[v],v});
			}
		}
	}
	int ans=INF;
	for(int x:tp[n]){
		chkmin(ans,dist[id(n,x)]);
	}
	cout<<ans<<endl;
}
