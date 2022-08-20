#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int MAXN=1e4+10;
int n,m,u,v,w,f[MAXN][14],dep[MAXN],dis[MAXN];
vector<pair<int,int> > Map[MAXN];

void dfs(int u,int fa,int w){
	dep[u]=dep[fa]+1;
	dis[u]=dis[fa]+w;
	f[u][0]=fa;
	for(int i=1;i<=13;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<Map[u].size();i++){
		int v=Map[u][i].first;
		if(v==fa) continue;
		dfs(v,u,Map[u][i].second);
	}
}

int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=13;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
		if(x==y) return x;
	}
	for(int i=13;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}

signed main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>u>>v>>w;
		Map[u].push_back(make_pair(v,w));
		Map[v].push_back(make_pair(u,w));
	}
	dfs(1,0,0);
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		cout<<dis[u]+dis[v]-dis[LCA(u,v)]*2<<endl;
	}
}

