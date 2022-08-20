#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int MAXN=1e5+10;
int n,q,x,y,f[MAXN][17],dep[MAXN];
vector<int> Map[MAXN];

void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=16;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<Map[u].size();i++){
		int v=Map[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
}

int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=16;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
		if(x==y) return x;
	}
	for(int i=16;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}

signed main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		Map[x].push_back(y);
		Map[y].push_back(x);
	}
	dfs(1,0);
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<dep[x]+dep[y]-dep[LCA(x,y)]*2<<endl;
	}
}

