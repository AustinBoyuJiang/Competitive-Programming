/*Author：AustinJiang
题目：Dining吃饭
时间复杂度：O(n^3)
算法：网络流，Dinic算法 
来源：Usaco2007 Open Gold */
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
const int N=1e3;
const int M=1e6;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,f,d,S,T,dep[N];
int tot=-1,to[M],val[M],nxt[M],head[N],h[N];

void addd(int u,int v,int w){
	to[++tot]=v;
	val[tot]=w;
	nxt[tot]=head[u];
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
		for(int i=head[u];~i;i=nxt[i]){
			int v=to[i];
			if(!dep[v]&&val[i]){
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
	for(int &i=h[u];~i;i=nxt[i]){
		int v=to[i];
		if(dep[v]==dep[u]+1&&val[i]){
			int res=DFS(v,min(flow,val[i]));
			val[i]-=res,val[i^1]+=res;
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
	cin>>n>>f>>d;
	S=0,T=f+d+n*2+1;
	for(int i=1;i<=f;i++)
		add(S,i,1);
	for(int i=1;i<=d;i++)
		add(f+i,T,1);
	for(int i=1;i<=n;i++){
		int a,b,x;
		cin>>a>>b;
		add(f+d+i,f+d+n+i,1);
		for(int j=1;j<=a;j++){
			cin>>x;
			add(x,f+d+i,1);
		}
		for(int j=1;j<=b;j++){
			cin>>x;
			add(f+d+n+i,f+x,1);
		}
	}
	cout<<Dinic()<<endl;
	return 0;
}

