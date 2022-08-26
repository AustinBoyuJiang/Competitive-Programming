/*Author：AustinJiang
题目：网络 
时间复杂度：O(n)
算法：强连通，Tarjan算法 
来源：CEOI 1996 */
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

int n,u,v,num,ans,dfn[N],low[N]; 
VI e[N];

void dfs(int u,int root){
	dfn[u]=low[u]=++num;
	int cnt=!root;
	for(auto v:e[u]){
		if(!dfn[v]){
			dfs(v,0);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]) cnt++;
		}
		else low[u]=min(low[u],dfn[v]);
	}
	if(cnt>1) ans++;
}

signed main(){
	while(scanf("%d",&n),n){
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		for(int i=1;i<=n;i++)
			e[i].clear();
		ans=num=0;
		while(scanf("%d",&u),u){
			while(getchar()!='\n'){
				scanf("%d",&v);
				e[u].pb(v);
				e[v].pb(u);
			}
		}
		dfs(1,1);
		printf("%d\n",ans);
	}
	return 0;
}

