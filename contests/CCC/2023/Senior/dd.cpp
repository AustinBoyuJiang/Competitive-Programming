#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'

template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;

const int N = 2e3+10;
const int M = 2e3+10;

int n,m,ans,del[N],dist[N],vis[N];
vector<pair<int,int>> ee[N];

struct edge{
	int u,v,w,c;
} e[M];

bool cmp(edge a,edge b){
	return a.c>b.c;
}

int get(int st,int ed){
	rep(i,1,n){
		ee[i].clear();
	}
	rep(i,1,m){
		if(del[i]) continue;
		ee[e[i].u].push_back({e[i].v,e[i].w});
		ee[e[i].v].push_back({e[i].u,e[i].w});
	}
	PQG<pair<int,int>> q;
	q.push({0,st});
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis)); 
	dist[st]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(pair<int,int> v:ee[u]){
			if(dist[u]+v.second<dist[v.first]){
				dist[v.first]=dist[u]+v.second;
				q.push({dist[v.first],v.first});
			}
		}
	}
	return dist[ed];
}

signed main(){
	cin>>n>>m;
	rep(i,1,m){
		int u,v,w,c;
		cin>>u>>v>>w>>c;
		e[i]={u,v,w,c};
	}
	sort(e+1,e+m+1,cmp);
	rep(i,1,m){
		int dis1=get(e[i].u,e[i].v);
		del[i]=1;
		int dis2=get(e[i].u,e[i].v);
		if(dis2!=dis1){
			del[i]=0;
			ans+=e[i].c;
//			cout<<i<<" "<<e[i].u<<" "<<e[i].v<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}
