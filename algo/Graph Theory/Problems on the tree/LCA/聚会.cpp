#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int MAXN=5e5+10;
int n,m,f[MAXN][21],dep[MAXN];
vector<int> Map[MAXN];

bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second<b.second;
}

void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=20;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<Map[u].size();i++){
		int v=Map[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
}

int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
		if(x==y) return x;
	}
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}

int get_dis(int x,int y,int z,int a,int b,int c){
	return dep[x]+dep[y]+dep[z]-dep[a]-dep[b]-dep[c];
}

signed main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		Map[x].push_back(y);
		Map[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++){
		int x,y,z,lca;
		cin>>x>>y>>z;
		int a=LCA(x,y);
		int b=LCA(x,z);
		int c=LCA(y,z);
		if(a==b)  lca=c;
		else if(b==c) lca=a;
		else lca=b;
		cout<<lca<<' '<<get_dis(x,y,z,a,b,c)<<endl;
	}
}

