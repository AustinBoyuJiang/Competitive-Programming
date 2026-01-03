/*Author: AustinJiang
题目: 欧拉回路 
时间复杂度: O(n+m)
算法: 欧拉回路，Hierholzer算法*/
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
const int M=4e5+10;

int t,n,m,cnt,tot=1,in[N],out[N],head[N],vis[M],ans[M];

struct edge{
	int to,nxt;
} e[M];

void add(int u,int v){
	in[v]++,out[u]++;
	e[++tot].nxt=head[u];
	e[tot].to=v;
	head[u]=tot;
}

void dfs1(int u,int id){
	for(int &i=head[u];i;i=e[i].nxt){
		if(vis[i]) continue;
		vis[i]=vis[i^1]=1;
		dfs1(e[i].to,i);
	}
	if(!id) return;
	if(id&1) ans[++cnt]=-(id/2);
	else ans[++cnt]=(id/2);
}

void dfs2(int u,int id){
	for(int &i=head[u];i;i=e[i].nxt){
		if(vis[i]) continue;
		vis[i]=1;
		dfs2(e[i].to,i);
	}
	if(!id) return;
	ans[++cnt]=id-1;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t>>n>>m;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		add(u,v);
		if(t==1) add(v,u);
	}
	for(int i=1;i<=n;i++)
		if((t==1&&in[i]&1)||(t==2&&in[i]!=out[i])){
			cout<<"NO"<<endl;
			return 0;
		}
	for(int i=1;i<=n;i++){
		if(!head[i]) continue;
		if(t==1) dfs1(i,0);
		else dfs2(i,0);
		break;
	}
	if(cnt<m){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	for(int i=cnt;i>=1;i--)
		cout<<ans[i]<<' ';
	return 0;
}

