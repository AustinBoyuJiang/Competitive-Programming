/*Author：AustinJiang
题目：消息的传递 
时间复杂度：O(n^2)
算法：强连通，Tarjan算法 
来源：暂无来源
*/
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

int n,tot,cnt,ans,e[N][N],dfn[N],low[N],flag[N],pos[N],in[N];
stack<int> stk;

void dfs(int u){
	dfn[u]=low[u]=++tot;
	flag[u]=1,stk.push(u);
	for(int v=1;v<=n;v++){
		if(!e[u][v]) continue;
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
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>e[i][j];
	for(int i=1;i<=n;i++)
		if(!dfn[i]) dfs(i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			in[pos[j]]+=pos[i]!=pos[j]&&e[i][j];
	for(int i=1;i<=cnt;i++)
		ans+=!in[i];
	cout<<ans<<endl;
	return 0;
}

