/*Author：AustinJiang
题目：间谍网络
时间复杂度：O(n)
算法：强连通，Tarjan算法，拓扑序 
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
const int N=3e3+10;

int n,p,r,tot,cnt,res,ans,val[N],dfn[N],low[N],flag[N],pos[N],mark[N],mv[N],mi[N],in[N];
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
	cin>>n>>p;
	for(int i=1;i<=p;i++){
		int x;
		cin>>x;
		cin>>val[x];
	}
	cin>>r;
	for(int i=1;i<=r;i++){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
	}
	memset(mv,0x3f,sizeof(mv));
	memset(mi,0x3f,sizeof(mi));
	for(int i=1;i<=n;i++){
		if(!dfn[i]) dfs(i);
		if(val[i]) mark[pos[i]]=1,mv[pos[i]]=min(mv[pos[i]],val[i]);
		else mi[pos[i]]=min(mi[pos[i]],i);
	}
	for(int i=1;i<=n;i++)
		for(auto j:e[i]){
			if(pos[i]==pos[j]) continue;
			ee[pos[i]].pb(pos[j]);
			in[pos[j]]++;
		}
	for(int i=1;i<=cnt;i++){
		if(in[i]) continue;
		if(mark[i]) ans+=mv[i];
		else q.push(i),res=1;
	}
	if(!res){
		cout<<"YES"<<endl;
		cout<<ans<<endl;
	}
	else{
		ans=INF;
		while(!q.empty()){
			int u=q.front(); q.pop();
			if(!mark[u]) ans=min(ans,mi[u]);
			for(auto v:ee[u]){
				mark[v]|=mark[u];
				if(--in[v]) q.push(v);
			}
		}
		cout<<"NO"<<endl;
		cout<<ans<<endl;
	}
	return 0;
}

