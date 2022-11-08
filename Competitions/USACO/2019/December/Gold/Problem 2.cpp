#include<bits/stdc++.h>
using namespace std;
const int E=1e5+10;
int n,m,u,v;
vector<int> eg[E],rd[E];
stack<int> cow[E];

struct cows{
	int tp,dep,f[17];
} st[E];

struct friends{
	int x,y,tp,lca,ans;
} e[E];

int LCA(int x,int y){
	if(st[x].dep>st[y].dep) swap(x,y);
	for(int i=16;i>=0;i--){
		if(st[x].dep<=st[st[y].f[i]].dep) y=st[y].f[i];
		if(x==y) return x;
	}
	for(int i=16;i>=0;i--){
		if(st[x].f[i]!=st[y].f[i]){
			x=st[x].f[i];
			y=st[y].f[i];
		}
	}
	return st[x].f[0];
}

void dfs1(int u,int fa){
	st[u].dep=st[fa].dep+1;
	st[u].f[0]=fa;
	for(int i=1;i<=16;i++) st[u].f[i]=st[st[u].f[i-1]].f[i-1];
	for(int i=0;i<eg[u].size();i++){
		int v=eg[u][i];
		if(v==fa) continue;
		dfs1(v,u);
	}
}

void dfs2(int u,int fa){
	cow[st[u].tp].push(u);
	for(int i=0;i<rd[u].size();i++){
		int id=rd[u][i];
		if(cow[e[id].tp].size()) e[id].ans|=st[cow[e[id].tp].top()].dep>=st[e[id].lca].dep;
	}
	for(int i=0;i<eg[u].size();i++){
		int v=eg[u][i];
		if(v==fa) continue;
		dfs2(v,u);
	}
	cow[st[u].tp].pop();
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>st[i].tp;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		eg[u].push_back(v);
		eg[v].push_back(u);
	}
	dfs1(1,0);
	for(int i=1;i<=m;i++){
		cin>>e[i].x>>e[i].y>>e[i].tp;
		e[i].lca=LCA(e[i].x,e[i].y);
		rd[e[i].x].push_back(i);
		rd[e[i].y].push_back(i);
	}
	dfs2(1,0);
	for(int i=1;i<=m;i++) cout<<e[i].ans;
}
