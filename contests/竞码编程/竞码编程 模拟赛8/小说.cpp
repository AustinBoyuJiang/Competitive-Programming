/*Author：AustinJiang
题目：小说
时间复杂度：O()
算法：
来源：
思路：
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
const int N=1e5+10;

int n,m,k,mx,f[N],dist[N],vis[N];

struct edge{
	int u,v,w;
} ed[N];

bool cmp(edge a,edge b){
	return a.w<b.w;
}

inline bool check(int x){
	VPI e[N];
	int i=1;
	while(i<=m&&ed[i].w<=x){
		e[ed[i].u].pb(mp(ed[i].v,0));
		e[ed[i].v].pb(mp(ed[i].u,0));
		i++;
	}
	for(;i<=m;i++){
		e[ed[i].u].pb(mp(ed[i].v,1));
		e[ed[i].v].pb(mp(ed[i].u,1));
	}
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	PQ<PI,VPI,greater<PI>> q;
	q.push(mp(0,1));
	dist[1]=0;
	while(!q.empty()){
		int u=q.top().sec; q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:e[u]){
			int v=i.fir;
			if(dist[u]+i.sec<dist[v]){
				dist[v]=dist[u]+i.sec;
				q.push(mp(dist[v],v));
			}
		}
	}
	return dist[n]<=k;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>ed[i].u>>ed[i].v>>ed[i].w;
	sort(ed+1,ed+m+1,cmp);
	int l=0,r=1000000,ans=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}

