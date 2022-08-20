/*Author：AustinJiang
题目：有源汇有上下界最大流
时间复杂度：O()
算法：
来源：
思路：
*/
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
const int M=3e4;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,s,t,S,T,sum,d[N],dep[N];
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
			if(val[i]&&!dep[v]){
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
		if(val[i]&&dep[v]==dep[u]+1){
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
	cin>>n>>m>>s>>t;
	S=0,T=n+1;
	for(int i=1;i<=m;i++){
		int s,t,l,u;
		cin>>s>>t>>l>>u;
		d[s]-=l,d[t]+=l;
		add(s,t,u-l);
	}
	for(int i=1;i<=n;i++){
		if(d[i]>0) add(S,i,d[i]);
		else if(d[i]<0) add(i,T,-d[i]);
		sum+=max(0ll,d[i]);
	}
	add(t,s,INF);
	if(sum==Dinic()){
		int res=val[tot];
		val[tot]=val[tot^1]=0;
		S=s,T=t;
		cout<<res+Dinic()<<endl;
	}
	else cout<<"please go home to sleep"<<endl;
	return 0;
}

