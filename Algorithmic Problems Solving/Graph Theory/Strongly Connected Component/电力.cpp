/*Author：AustinJiang
题目：割点(电力)
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
const int N=2e4+10;

int n,m,num,tot,ans,dfn[N],low[N],flag[N];
stack<int> stk;
VI e[N];

void dfs(int u,int root){
	dfn[u]=low[u]=++num;
	flag[u]=1,stk.push(u);
	int cnt=!root;
	for(auto v:e[u]){
		if(!dfn[v]){
			dfs(v,0);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]) cnt++;
		}
		else if(flag[v]) low[u]=min(low[u],dfn[v]);
	}
	ans=max(ans,cnt);
	while(u!=stk.top())
		flag[stk.top()]=0,stk.pop();
	flag[u]=0,stk.pop();
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n>>m,n){
		memset(dfn,0,sizeof(dfn));
		ans=tot=0;
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1;i<=m;i++){
			int u,v;
			cin>>u>>v;
			e[u+1].pb(v+1);
			e[v+1].pb(u+1);
		}
		for(int i=1;i<=n;i++)
			if(!dfn[i]) tot++,dfs(i,1);
		cout<<ans+tot-1<<endl;
	}
	return 0;
}

