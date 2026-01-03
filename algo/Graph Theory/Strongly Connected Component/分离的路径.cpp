/*Author：AustinJiang
题目：割边(桥)
时间复杂度：O(n)
算法：强连通，欧拉回路 */
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
const int N=1e3+10;

int n,m,id,num,tot,cnt,dfn[N],low[N],instk[N],co[N],vis[N],du[N];
stack<int> stk;
VPI e[N];

void dfs(int u,int fa){
	dfn[u]=low[u]=++num;
	instk[u]=1,stk.push(u);
	for(auto i:e[u]){
		int v=i.fir;
		if(vis[i.sec]) continue;
		vis[i.sec]=1;
		if(!dfn[v]) dfs(v,u);
		if(instk[v]) low[u]=min(low[u],low[v]);
	}
	if(dfn[u]!=low[u]) return;
	co[u]=++tot;
	while(stk.top()!=u){
		co[stk.top()]=tot;
		instk[stk.top()]=0,stk.pop();
	}
	instk[u]=0,stk.pop();
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		e[u].pb(mp(v,++id));
		e[v].pb(mp(u,id));
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		for(auto j:e[i]){
			if(co[i]==co[j.fir]) continue;
			du[co[i]]++;
			du[co[j.fir]]++;
		}
	if(tot==1) cout<<0<<endl;
	else{
		for(int i=1;i<=tot;i++)
			if(du[i]/2<2) cnt++;
		cout<<(cnt+1)/2<<endl;
	}
	return 0;
}

