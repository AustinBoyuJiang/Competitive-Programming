/*Author：AustinJiang
题目：航空路线问题 
时间复杂度：O()
算法：网络流24题 
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
const int V=N*2;
const int E=V*V*2;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,cnt,S,T,len[2],ans[2][N],dist[V],inq[V],vis[V];
string name[N];
map<string,int> id;
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
	for(int i=S;i<=T;i++){
		dist[i]=-INF;
		h[i]=head[i];
	}
	queue<int> q;
	q.push(S);
	dist[S]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=h[u];~i;i=e[i].nxt){
			int v=e[i].to,w=e[i].flow,c=e[i].cost;
			if(w&&dist[u]+c>dist[v]){
				dist[v]=dist[u]+c;
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
	return dist[T]!=-INF;
}

int DFS(int u,int flow){
	if(u==T){
		cnt+=flow*dist[T];
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
			if(!res) dist[v]=-1;
			if(!flow) break;
		}
	}
	vis[u]=0;
	return ans;
}

int Dinic(){
	int ans=0;
	while(SPFA())
		ans+=DFS(S,INF);
	return ans;
}

void DFS2(int u,int pos,int k){
	if(u<=n){
		if(k==0||k==1) ans[0][len[0]=pos]=u;
		if(k==0||k==2) ans[1][len[1]=pos]=u;
	}
	int cnt=k+(u==1);
	for(int i=head[u];~i;i=e[i].nxt){
		int v=e[i].to,w=e[i].flow;
		if((i&1)==0&&!w) DFS2(v,pos+(u<=n),cnt++);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(head,-1,sizeof(head));
	cin>>n>>m;
	S=1,T=n+n;
	for(int i=1;i<=n;i++){
		cin>>name[i];
		id[name[i]]=i;
	}
	add(1,1+n,2,0);
	add(n,n+n,2,0);
	for(int i=2;i<n;i++)
		add(i,i+n,1,1);
	for(int i=1;i<=m;i++){
		string a,b;
		cin>>a>>b;
		if(id[a]>id[b]) swap(a,b);
		add(id[a]+n,id[b],1,0);
	}
	if(Dinic()==2){
		DFS2(S,0,0);
		cout<<cnt+2<<endl;
		for(int i=0;i<=len[0];i++)
			cout<<name[ans[0][i]]<<endl;
		for(int i=len[1]-1;i>=0;i--)
			cout<<name[ans[1][i]]<<endl;
	}
	else cout<<"No Solution!"<<endl;
	return 0;
}

