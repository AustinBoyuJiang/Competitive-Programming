/*Author: AustinJiang
题目: 相框 
时间复杂度: O(n+m)
算法: 欧拉回路，DFS*/
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
const int N=1e5+1010;

int n,m,id,cnt,ans,flag1[N],flag2[N],vis[N],d[N],f[N];
VI e[N];

void dfs(int u){
	vis[u]=1,f[u]=id;
	for(auto v:e[u])
		if(!vis[v]) dfs(v);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		if(!u) u=++n;
		if(!v) v=++n;
		e[u].pb(v);
		e[v].pb(u);
		d[u]++,d[v]++;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]&&d[i]) id++,dfs(i);
	for(int i=1;i<=n;i++){
		if(d[i]&1) cnt++,flag1[f[i]]=1;
		if(d[i]>2) ans++,flag2[f[i]]=1;
	}
	if(id>1)
	for(int i=1;i<=id;i++){
		if(!flag1[i]) cnt+=2;
		if(!flag1[i]&&!flag2[i]) ans++;
	}
	cout<<ans+cnt/2<<endl;
	return 0;
}
