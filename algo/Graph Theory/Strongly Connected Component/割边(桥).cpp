/*Author：AustinJiang
题目：割边(桥)
时间复杂度：O(n)
算法：强连通，Tarjan */
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
const int N=1e5+10;

int n,m,id,num,ans,dfn[N],low[N],instk[N],vis[N];
stack<int> stk;
VPI e[N];

void dfs(int u){
	dfn[u]=low[u]=++num;
	for(auto i:e[u]){
		int v=i.fir;
		if(vis[i.sec]) continue;
		vis[i.sec]=1;
		if(!dfn[v]){
			dfs(v);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]) ans++;
		}
		else low[u]=min(low[u],dfn[v]);
	}
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
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

