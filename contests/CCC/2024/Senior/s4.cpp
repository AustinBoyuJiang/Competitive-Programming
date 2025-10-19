#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'

const int N = 2e5+10;
const int M = 2e5+10;

struct edges{
	int u,v;
} edge[N];

int n,m,dep[N],col[M];
pair<int,int> fa[N];
vector<pair<int,int>> e[N],ee[N];

void dfs(int u,int father){
	dep[u]=dep[father]+1;
	for(pair<int,int> edge:e[u]){
		int v=edge.first;
		int id=edge.second;
		if(dep[v]>0) continue;
		fa[v]={u,id};
		col[id]=dep[u]%2;
		dfs(v,u);
	}
}

void dfs2(int u){
	for(pair<int,int> edge:ee[u]){
		int v=edge.first;
		int id=edge.second;
		col[id]=dep[u]%2;
		dep[v]=dep[u]+1;
		dfs2(v);
	}
}

signed main(){
	cin>>n>>m;
	rep(i,1,m){
		int u,v;
		cin>>u>>v;
		edge[i]={u,v};
		e[u].push_back({v,i});
		e[v].push_back({u,i});
		col[i]=-1;
	}
	rep(i,1,n){
		if(dep[i]>0) continue;
		dfs(i,0);
	}
//	rep(i,1,m){
//		int u=edge[i].u;
//		int v=edge[i].v;
////		if(dep[u]==dep[v]){
////			fa[v]={u,i};
////		}
//	}
//	rep(i,1,n){
//		dep[i]=0;
//		ee[fa[i].first].push_back({i,fa[i].second});
//	}
//	dfs2(0);
	rep(i,1,m){
		int u=edge[i].u;
		int v=edge[i].v;
		assert(dep[u]!=dep[v]);
	}
	rep(i,1,m){
		if(col[i]==0){
			cout<<'R';
		}
		else if(col[i]==1){
			cout<<'B';
		}
		else{
			cout<<'G';
		}
	}
	cout<<endl;
	return 0;
}

