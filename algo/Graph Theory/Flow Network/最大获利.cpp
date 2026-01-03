/*Author：AustinJiang
题目：最大获利 
时间复杂度：O()
算法：
来源：NOI2006
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
const int N=6e4;
const int M=N*6;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,sum,S,T,dep[N];
int tot=-1,head[N],h[N];

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
	cin>>n>>m;
	S=0,T=n+m+1;
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		add(S,i,p);
	}
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		sum+=c;
		add(a,n+i,INF);
		add(b,n+i,INF);
		add(n+i,T,c);
	}
	cout<<sum-Dinic()<<endl;
	return 0;
}

