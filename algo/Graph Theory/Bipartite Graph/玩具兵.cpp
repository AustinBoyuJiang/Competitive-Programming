/*Author：AustinJiang
题目：玩具兵 
时间复杂度：O(k*2*n*m*log(n*m))
算法：
来源：
思路：
*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PI pair<int,int>
#define VI vector<int>
#define VPI vector<PI>
#define PQ priority_queue
using namespace std;
const int INF=0x3f3f3f3f;
const int N=110;

int n,m,k,t,mid,h[N][N],dist[N][N],vis[N],match[N];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

struct start{
	int x,y;
	VPI e;
} st[N];

struct end{
	int x,y,r;
} ed[N];

struct cmp {
    bool operator()(const PI&a, const PI&b) {
        return dist[a.fir][a.sec]>dist[b.fir][b.sec];
    }
};

void dijkstra(int x,int y,bool k){
	bool state[N][N],vis[N][N];
	PQ<PI,VPI,cmp> q;
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	dist[x][y]=0;
	state[x][y]=k;
	q.push(mp(x,y));
	while(!q.empty()){
		int x=q.top().fir,y=q.top().sec; q.pop();
		if(vis[x][y]) continue;
		vis[x][y]=1;
		for(int i=0;i<4;i++){
			int nx=x+dir[i][0];
			int ny=y+dir[i][1];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m){
				bool d=state[x][y]?h[x][y]<h[nx][ny]:h[x][y]>h[nx][ny];
				if(dist[x][y]+d<dist[nx][ny]){
					dist[nx][ny]=dist[x][y]+d;
					state[nx][ny]=state[x][y]^d;
					q.push(mp(nx,ny));
				}
			}
		}
	}
}

bool find(int u){
	if(vis[u]) return 0;
	vis[u]=1;
	for(int i=0;i<st[u].e.size();i++){
		if(st[u].e[i].sec>mid) continue;
		int v=st[u].e[i].fir;
		if(!match[v]||find(match[v])){
			match[v]=u;
			return 1;
		}
	}
	return 0;
}

bool check(){
	int cnt=0;
	memset(match,0,sizeof(match));
	for(int i=1;i<=k*2;i++){
		memset(vis,0,sizeof(vis));
		if(find(i)) cnt++;
	}
	return cnt+mid>=k*2;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k>>t;
	for(int i=1;i<=k*2+1;i++)
		cin>>st[i].x>>st[i].y;
	for(int i=1;i<=t;i++)
		cin>>ed[i].x>>ed[i].y>>ed[i].r;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>h[i][j];
	for(int i=1;i<=k*2;i++){
		dijkstra(st[i].x,st[i].y,i>k);
		for(int j=1,cnt=1;j<=t;j++)
			for(int k=1;k<=ed[j].r;k++,cnt++)
				st[i].e.pb(mp(cnt,dist[ed[j].x][ed[j].y]));
	}
	int l=0,r=k*2,ans;
	while(l<=r){
		mid=l+r>>1;
		if(check()) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}

