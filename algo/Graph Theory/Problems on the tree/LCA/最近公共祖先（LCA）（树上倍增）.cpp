#include<bits/stdc++.h>
using namespace std;
const int E=1e3+10;
int n,q,x,y,f[E][11],dep[E];
vector<int> Map[E];

void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=10;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<Map[u].size();i++){
		int v=Map[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
}

int lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	for(int i=10;i>=0;i--){
		if(dep[x]<=dep[f[y][i]]) y=f[y][i];
		if(x==y) return x;
	}
	for(int i=10;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&x,&y);
		Map[x].push_back(y);
		Map[y].push_back(x);
	}
	dfs(1,0);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d %d",&x,&y);
		printf("%d\n",lca(x,y));
	}
}
