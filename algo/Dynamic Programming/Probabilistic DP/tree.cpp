/*Author：AustinJiang
题目：tree
时间复杂度：O(n*log(n))
算法：概率期望dp，树上差分，LCA */
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
const int N=1e5+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,q,dep[N],f[N][20];
int up[N],down[N],sum[N],sumUp[N],sumDown[N];
VI e[N];

//求up[u]表示u到fa的期望步数 
void dfs1(int u,int fa){
	up[u]=1;
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs1(v,u);
		up[u]+=up[v]+1;
	}
}

//求down[u]表示fa到fu的期望步数 
void dfs2(int u,int fa){
	down[u]=sum[fa]-up[u];
	for(auto v:e[u]){
		if(v==fa) sum[u]+=down[u]+1;
		else sum[u]+=up[v]+1;
	}
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs2(v,u);
	}
}

void dfs3(int u,int fa){
	sumUp[u]=sumUp[fa]+up[u];
	sumDown[u]=sumDown[fa]+down[u];
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=16;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs3(v,u);
	}
}

int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=16;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
		if(x==y) return x;
	}
	for(int i=16;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs1(1,0);
	dfs2(1,0);
	dfs3(1,0);
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		int x=LCA(u,v);
		cout<<sumUp[u]-sumUp[x]+sumDown[v]-sumDown[x]<<endl;
	}
	return 0;
}

