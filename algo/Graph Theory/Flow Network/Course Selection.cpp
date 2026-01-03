/*Author：AustinJiang
题目：Course Selection
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
const int N=110;
const int V=N*N;
const int E=V*4;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,k,S,T,dep[V],a[N][N],c[N][N];
int tot=-1,head[V],h[V];

struct edge{
	int to,flow,nxt;
} e[E];

int ID(int x,int y){
	return (x-1)*m+y;
}

void addd(int u,int v,int w){
	e[++tot].to=v;
	e[tot].flow=w;
	e[tot].nxt=head[u];
	head[u]=tot;
}

void add(int u,int v,int w){
	addd(u,v,w);
	addd(v,u,0);
}

bool BFS(){
	memcpy(h,head,sizeof(h));
	memset(dep,0,sizeof(dep));
	queue<int> q;
	q.push(S);
	dep[S]=1;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=h[u];~i;i=e[i].nxt){
			int v=e[i].to,w=e[i].flow;
			if(w&&!dep[v]){
				dep[v]=dep[u]+1;
				q.push(v);
			}
		}
	}
	return dep[T];
}

int DFS(int u,int flow){
	if(u==T) return flow;
	int ans=0;
	for(int &i=h[u];~i;i=e[i].nxt){
		int v=e[i].to,&w=e[i].flow;
		if(w&&dep[v]==dep[u]+1){
			int res=DFS(v,min(w,flow));
			w-=res,e[i^1].flow+=res;
			ans+=res,flow-=res;
			if(!res) dep[v]=0;
			if(!flow) break;
		}
	}
	return ans;
}

int Dinic(){
	int ans=0;
	while(BFS())
		ans+=DFS(S,INF);
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(head,-1,sizeof(head));
	cin>>n>>m>>k;
	S=0,T=n*m+1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]==-1) c[i][j]=INF;
			else c[i][j]=100-a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		add(S,ID(i,1),c[i][1]);
		for(int j=2;j<=m;j++)
			add(ID(i,j-1),ID(i,j),c[i][j]);
		add(ID(i,m),T,INF);
	}
	for(int i=1;i<=k;i++){
		int a,b;
		cin>>a>>b;
		add(S,ID(b,1),INF);
		for(int j=2;j<=m;j++)
			add(ID(a,j-1),ID(b,j),INF);
	}
	printf("%.2lf\n",100-Dinic()*1.0/n);
	return 0;
}

