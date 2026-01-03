/*Author：AustinJiang
题目：Truck Delivery
时间复杂度：O(t*q*log(L)*log(A))
算法： 线段树，DFS，辗转相除法 
来源：Round B 2021 - Kick Start 2021 */
#include<bits/stdc++.h>
#define int long long
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
const int N=5e4+10;
const int Q=1e5+10;
const int L=2e5;

int t,n,m,ans[Q],st[L*4+10];
VPI q[N];

struct edge{
	int to,l,a;
};

vector<edge> e[N];

int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

void update(int rt,int l,int r,int x,int y){
	if(l==r){
		st[rt]=y;
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid) update(rt*2,l,mid,x,y);
	else update(rt*2+1,mid+1,r,x,y);
	st[rt]=gcd(st[rt*2],st[rt*2+1]);
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return st[rt];
	int mid=(l+r)/2;
	if(y<=mid) return query(rt*2,l,mid,x,y);
	else if(x>mid) return query(rt*2+1,mid+1,r,x,y);
	else return gcd(query(rt*2,l,mid,x,mid),query(rt*2+1,mid+1,r,mid+1,y));
}

void dfs(int u,int fa){
	for(auto i:q[u]){
		ans[i.fir]=query(1,1,L,1,i.sec);
	}
	for(auto i:e[u]){
		if(i.to==fa) continue;
		update(1,1,L,i.l,i.a);
		dfs(i.to,u);
		update(1,1,L,i.l,0);
	}
}

void solve(int ca){
	memset(ans,0,sizeof(ans));
	memset(st,0,sizeof(st));
	for(int i=1;i<=n;i++){
		e[i].clear();
		q[i].clear();
	}
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int u,v,x,y;
		cin>>u>>v>>x>>y;
		e[u].pb((edge){v,x,y});
		e[v].pb((edge){u,x,y});
	}
	for(int i=1;i<=m;i++){
		int c,w;
		cin>>c>>w;
		q[c].pb(mp(i,w));
	}
	dfs(1,0);
	cout<<"Case #"<<ca<<": ";
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	cout<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++)
		solve(i);
	return 0;
}

