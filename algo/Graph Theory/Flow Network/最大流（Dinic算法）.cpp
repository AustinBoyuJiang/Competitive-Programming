/*Author：AustinJiang
题目：最大流 
时间复杂度：O(n^2*m)
算法：网络流，Dinic算法 */
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
const int INF=0x3f3f3f3f;
const int N=2e3;
const int M=3e5;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,s,t,dep[N];
int tot=-1,to[M],val[M],nxt[M],head[N],h[N];

void add(int u,int v,int w){
	to[++tot]=v;
	val[tot]=w;
	nxt[tot]=head[u];
	head[u]=tot;
}

bool bfs(){
	for(int i=1;i<=n;i++){
		h[i]=head[i];
		dep[i]=0;
	}
	queue<int> q;
	q.push(s);
	dep[s]=1;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=head[u];~i;i=nxt[i]){
			if(!dep[to[i]]&&val[i]){
				dep[to[i]]=dep[u]+1;
				q.push(to[i]);
			}
		}
	}
	return dep[t];
}

int dfs(int u,int flow){
	if(u==t) return flow;
	int ans=0;
	for(int &i=h[u];~i;i=nxt[i]){
		if(dep[to[i]]==dep[u]+1&&val[i]){
			int res=dfs(to[i],min(flow,val[i]));
			val[i]-=res,val[i^1]+=res;
			ans+=res,flow-=res;
			if(!res) dep[to[i]]=0;
			if(!flow) break;
		}
	}
	return ans;
}

int maxFlow(){
	int ans=0;
	while(bfs())
		ans+=dfs(s,INF);
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
		add(v,u,0);
	}
	cout<<maxFlow()<<endl;
	return 0;
}

