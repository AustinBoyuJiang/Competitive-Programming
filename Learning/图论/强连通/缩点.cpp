/*Author: AustinJiang
题目: 缩点 
时间复杂度: O(n)
算法: 强连通，Tarjan算法，拓扑序*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PI pair<int,int>
#define VI vector<int>
#define VPI vector<PI>
#define PQ priority_queue
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e4+10;

int n,m,tot,cnt,ans,val[N],dfn[N],low[N],flag[N],pos[N],in[N],sum[N],dist[N];
stack<int> stk;
queue<int> q;
VI e[N],ee[N];

void dfs(int u){
	dfn[u]=low[u]=++tot;
	flag[u]=1,stk.push(u);
	for(auto v:e[u]){
		if(!dfn[v]) dfs(v);
		if(flag[v]) low[u]=min(low[u],low[v]);
	}
	if(dfn[u]!=low[u]) return;
	pos[u]=++cnt;
	while(stk.top()!=u){
		pos[stk.top()]=cnt;
		flag[stk.top()]=0,stk.pop();
	}
	flag[u]=0,stk.pop();
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>val[i];
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) dfs(i);
		sum[pos[i]]+=val[i];
	}
	for(int i=1;i<=n;i++)
		for(auto j:e[i]){
			if(pos[i]==pos[j]) continue;
			ee[pos[i]].pb(pos[j]);
			in[pos[j]]++;
		}
	for(int i=1;i<=cnt;i++){
		if(in[i]) continue;
		q.push(i);
		dist[i]=sum[i];
	}
	while(!q.empty()){
		int u=q.front(); q.pop();
		ans=max(ans,dist[u]);
		for(auto v:ee[u]){
			dist[v]=max(dist[v],dist[u]+sum[v]);
			if(!--in[v]) q.push(v);
		}
	}
	cout<<ans<<endl;
	return 0;
}

