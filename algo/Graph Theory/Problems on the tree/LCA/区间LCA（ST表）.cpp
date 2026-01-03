/*Author：AustinJiang
题目：区间LCA 
时间复杂度：O(n*log(n))
算法：LCA，ST表 */
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
const int N=1e5+10;

int n,q,dep[N],f[N][17],st[N][20];
VI e[N];

void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=16;i++)
		f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:e[u])
		if(v!=fa) dfs(v,u);
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
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		e[a].pb(b);
		e[b].pb(a);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		st[i][0]=i;
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=LCA(st[i][j-1],st[i+(1<<j-1)][j-1]);
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int l,r,d;
		cin>>l>>r;
		d=log2(r-l+1);
		cout<<LCA(st[l][d],st[r-(1<<d)+1][d])<<endl;
	}
	return 0;
}

