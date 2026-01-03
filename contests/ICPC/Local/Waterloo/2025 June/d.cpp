#pragma GCC optimize(2)

#include<bits/stdc++.h>
using namespace std;

//#define int long long

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

const int INF = 0x3f3f3f3f;

const int N = 1e6+10;

int t,n,dis[N];
VI e[N];

void dfs(int u,int fa,int dist){
	dis[u]=dist;
	for(int v:e[u]){
		if(v==fa) continue;
		dfs(v,u,dist+1);
	}
}

int get(int st){
	dfs(st,0,0);
	int res=1;
	rep(i,1,n){
		if(dis[i]>dis[res]){
			res=i;
		}
	}
	return res;
}

signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		rep(i,1,n){
			e[i].clear();
		}
		rep(i,2,n){
			int u,v;
			cin>>u>>v;
			u++;
			v++;
			e[u].pb(v);
			e[v].pb(u);
		}
		int u=get(1);
		int v=get(u);
		int ans=0;
		rep(i,1,n){
			ans=max(ans,dis[i]);
		}
		cout<<(ans+1)/2<<endl;
	}
	
}

