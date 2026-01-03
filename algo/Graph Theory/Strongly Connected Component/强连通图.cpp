/*Author: AustinJiang
题目: 强连通图 
时间复杂度: O(t*n)
算法: 强连通，Tarjan算法*/
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

int t,n,m,cnt,tot,dfn[N],low[N],flag[N];
stack<int> stk;
VI e[N];

void dfs(int u){
	dfn[u]=low[u]=++tot;
	flag[u]=1,stk.push(u);
	for(auto v:e[u]){
		if(!dfn[v]) dfs(v);
		if(flag[v]) low[u]=min(low[u],low[v]);
	}
	if(dfn[u]!=low[u]) return;
	while(stk.top()!=u)
		flag[stk.top()]=0,stk.pop();
	flag[u]=0,stk.pop();
	cnt++;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		memset(dfn,0,sizeof(dfn));
		for(int i=1;i<=n;i++)
			e[i].clear();
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			int u,v;
			cin>>u>>v;
			e[u].pb(v);
		}
		tot=0,cnt=0;
		for(int i=1;i<=n;i++)
			if(!dfn[i]) dfs(i);
		if(cnt>1) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
