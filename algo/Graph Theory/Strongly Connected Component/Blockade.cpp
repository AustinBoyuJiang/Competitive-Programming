/*Author：AustinJiang
题目：Blockade
时间复杂度：O(n)
算法：
来源：
思路：
*/
#include<bits/stdc++.h>
#define int long long
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
const int M=1e6+10;

int n,m,num,tot,head[N],dfn[N],low[N],size[N],ans[N];

struct edge{
	int to,nxt;
}e[M];

void add(int u,int v){
	e[++tot].nxt=head[u];
	e[tot].to=v;
	head[u]=tot;
}

void dfs(int u){
	dfn[u]=low[u]=++num;
	size[u]=1;
	int cnt=0;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(!dfn[v]){
			dfs(v);
			size[u]+=size[v];
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]) ans[u]+=size[v]*(n-size[v]),cnt+=size[v];
		}
		else low[u]=min(low[u],dfn[v]);
	}
	ans[u]+=(n-cnt-1)*(cnt+1)+(n-1);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	dfs(1);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
	return 0;
}

