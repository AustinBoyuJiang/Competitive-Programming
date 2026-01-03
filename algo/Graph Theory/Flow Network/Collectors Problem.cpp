/*Author：AustinJiang
题目：Collectors Problem
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
const int N=100;
const int M=1e3;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int t,n,m,S=0,T=1,dep[N],a[N][N];
int tot,head[N],h[N];

struct edge{
	int to,flow,nxt;
} e[M];

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
		for(int i=head[u];~i;i=e[i].nxt){
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
			flow-=res,ans+=res;
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

void solve(int Case){
	tot=-1;
	memset(a,0,sizeof(a));
	memset(head,-1,sizeof(head));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			cin>>x;
			a[i][x]++;
		}
	}
	for(int i=1;i<=m;i++){
		add(S,n+i,a[1][i]);
		add(n+i,T,1);
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!a[i][j]) add(n+j,i,1);
			else add(i,n+j,a[i][j]-1);
		}
	}
	printf("Case #%d: %d\n",Case,Dinic());
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++)
		solve(i);
	return 0;
}

