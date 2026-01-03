/*Author：AustinJiang
题目：嗅探器
时间复杂度：O(n)
算法：强连通 
来源：ZJOI 2004 */
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
const int N=110;

int n,u,v,a,b,num,ans=INF,dfn[N],low[N];
VI e[N];

bool check(int x){
	if(dfn[a]>=dfn[x]&&dfn[x]>dfn[b]) return 1;
	if(dfn[a]<dfn[x]&&dfn[x]<=dfn[b]) return 1;
	return 0;
}

void dfs(int u,int fa){
	dfn[u]=low[u]=++num;
	for(auto v:e[u]){
		if(!dfn[v]){
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]&&u!=a&&u!=b&&check(v)) ans=min(ans,u);
		}
		else if(v!=fa) low[u]=min(low[u],dfn[v]);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(cin>>u>>v,u){
		e[u].pb(v);
		e[v].pb(u);
	}
	cin>>a>>b;
	dfs(a,a);
	if(ans==INF) cout<<"No solution"<<endl;
	else cout<<ans<<endl;
	return 0;
}

