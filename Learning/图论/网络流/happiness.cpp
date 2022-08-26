/*Author：AustinJiang
题目：
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
const int E=V*12;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,sum,S,T,a[N][N][2],b[N][N][4],dep[V];
int tot=-1,head[V],h[V];

struct edge{
	int to,nxt;
	double flow;
} e[E];

int id(int x,int y){
	return (x-1)*m+y;
}

void addd(int u,int v,double w){
	e[++tot].to=v;
	e[tot].flow=w;
	e[tot].nxt=head[u];
	head[u]=tot;
}

void add(int u,int v,double w){
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
			int v=e[i].to;
			double w=e[i].flow;
			if(w&&!dep[v]){
				dep[v]=dep[u]+1;
				q.push(v);
			}
		}
	}
	return dep[T];
}

double DFS(int u,double flow){
	if(u==T) return flow;
	double ans=0;
	for(int &i=h[u];~i;i=e[i].nxt){
		int v=e[i].to;
		double &w=e[i].flow;
		if(w&&dep[v]==dep[u]+1){
			double res=DFS(v,min(w,flow));
			w-=res,e[i^1].flow+=res;
			ans+=res,flow-=res;
			if(!res) dep[v]=0;
			if(!flow) break;
		}
	}
	return ans;
}

double Dinic(){
	double ans=0;
	while(BFS())
		ans+=DFS(S,INF);
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(head,-1,sizeof(head));
	cin>>n>>m;
	S=0,T=n*m+1;
	for(int k=0;k<=1;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j][k];
				sum+=a[i][j][k];
			}
		}
	}
	for(int k=0;k<=1;k++){
		for(int i=2;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>b[i][j][k];
				sum+=b[i][j][k];
			}
		}
	}
	for(int k=2;k<=3;k++){
		for(int i=1;i<=n;i++){
			for(int j=2;j<=m;j++){
				cin>>b[i][j][k];
				sum+=b[i][j][k];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			add(S,id(i,j),a[i][j][0]+(b[i][j][0]+b[i+1][j][0]+b[i][j][2]+b[i][j+1][2])/2.0);
			add(id(i,j),T,a[i][j][1]+(b[i][j][1]+b[i+1][j][1]+b[i][j][3]+b[i][j+1][3])/2.0);
			if(i>1) add(id(i,j),id(i-1,j),(b[i][j][0]+b[i][j][1])/2.0);
			if(i<n) add(id(i,j),id(i+1,j),(b[i+1][j][0]+b[i+1][j][1])/2.0);
			if(j>1) add(id(i,j),id(i,j-1),(b[i][j][2]+b[i][j][3])/2.0);
			if(j<m) add(id(i,j),id(i,j+1),(b[i][j+1][2]+b[i][j+1][3])/2.0);
		}
	}
	printf("%.0lf\n",sum-Dinic());
	return 0;
}

