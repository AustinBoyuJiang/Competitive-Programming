/*Author：AustinJiang
题目：棋盘覆盖 
时间复杂度：O(n^4)
算法：二分图 */
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
const int N=1e4+100;

int n,m,ans,Map[N],vis[N],match[N];
VI e[N];

int ID(int x,int y){
	return (x-1)*n+y;
}

bool OK(int x,int y){
	if(x<1||y<1||x>n||y>n) return 0;
	if(Map[ID(x,y)]) return 0;
	return 1;
}

int find(int u){
	for(auto v:e[u]){
		if(vis[v]) continue;
		vis[v]=1;
		if(!match[v]||find(match[v])){
			match[v]=u;
			return 1;
		}
	}
	return 0;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		Map[ID(x,y)]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i+j&1||Map[ID(i,j)]) continue;
			if(OK(i+1,j)) e[ID(i,j)].pb(ID(i+1,j));
			if(OK(i,j+1)) e[ID(i,j)].pb(ID(i,j+1));
			if(OK(i-1,j)) e[ID(i,j)].pb(ID(i-1,j));
			if(OK(i,j-1)) e[ID(i,j)].pb(ID(i,j-1));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i+j&1||Map[ID(i,j)]) continue;
			memset(vis,0,sizeof(vis));
			if(find(ID(i,j))) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
