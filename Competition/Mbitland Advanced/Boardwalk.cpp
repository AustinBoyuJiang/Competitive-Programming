/*Author：AustinJiang
题目：Boardwalk
时间复杂度：O()
算法：
来源：
思路：
*/
#include<bits/stdc++.h>
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
const int N=210;
const int V=N;
const int E=V*4;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,k,ans,S,T,a[N],dist[V],inq[V],vis[V];
int tot=-1,head[V],h[V];

struct edge{
	int to,flow,cost,nxt;
} e[E];

void addd(int u,int v,int w,int c){
	e[++tot].to=v;
	e[tot].flow=w;
	e[tot].cost=c;
	e[tot].nxt=head[u];
	head[u]=tot;
}

void add(int u,int v,int w,int c){
	addd(u,v,w,c);
	addd(v,u,0,-c);
}

bool SPFA(){
	memcpy(h,head,sizeof(h));
	memset(dist,0x3f,sizeof(dist));
	queue<int> q;
	q.push(S);
	dist[S]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=head[u];~i;i=e[i].nxt){
			int v=e[i].to,w=e[i].flow,c=e[i].cost;
			if(w&&dist[u]+c<dist[v]){
				dist[v]=dist[u]+c;
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
	return dist[T]!=INF;
}

int DFS(int u,int flow){
	if(u==T){
		ans+=flow*dist[T];
		return flow;
	}
	vis[u]=1;
	int ans=0;
	for(int &i=h[u];~i;i=e[i].nxt){
		int v=e[i].to,&w=e[i].flow,c=e[i].cost;
		if(!vis[v]&&w&&dist[v]==dist[u]+c){
			int res=DFS(v,min(w,flow));
			w-=res,e[i^1].flow+=res;
			ans+=res,flow-=res;
			if(!res) dist[v]=INF;
			if(!flow) break;
		}
	}
	vis[u]=0;
	return ans;
}

void Dinic(){
	while(SPFA())
		DFS(S,INF);
}

signed main(){
//	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(head,-1,sizeof(head));
	cin>>n>>k;
	S=n+k+1,T=n+k+2;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		int d=a[i]-a[(i+n-2)%n+1];
		if(d>0) add(i,T,abs(d),0);
		if(d<0) add(S,i,abs(d),0);
	}
	for(int i=1;i<=k;i++){
		int l,r,c;
		cin>>l>>r>>c;
		add(l,r%n+1,INF,c);
	}
	Dinic();
	cout<<ans<<endl;
	return 0;
}

