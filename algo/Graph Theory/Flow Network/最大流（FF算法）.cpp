/*Author：AustinJiang
题目：最大流 
时间复杂度：O(m*F)
算法：最大流，FF算法 */
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define random(a,b) rand()%(b-a+1)+a
#define PQ priority_queue
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=1e5+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,s,t,vis[N];
int id,to[N],val[N],nxt[N],head[N];

void addd(int u,int v,int w){
	to[id]=v;
	val[id]=w;
	nxt[id]=head[u];
	head[u]=id++;
}

void add(int u,int v,int w){
	addd(u,v,w);
	addd(v,u,0);
}

int dfs(int u,int flow){
	if(u==t) return flow;
	vis[u]=1;
	for(int i=head[u];~i;i=nxt[i]){
		if(!vis[to[i]]&&val[i]>0){
			int d=dfs(to[i],min(flow,val[i]));
			if(d>0){
				val[i]-=d;
				val[i^1]+=d;
				return d;
			}
		}
	}
	return 0;
}

int maxFlow(){
	int ans=0;
	while(1){
		memset(vis,0,sizeof(vis));
		int d=dfs(s,INF);
		if(!d) break;
		ans+=d;
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>s>>t;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	cout<<maxFlow()<<endl;
	return 0;
}

