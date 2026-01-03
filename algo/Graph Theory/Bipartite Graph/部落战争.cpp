/*Author：AustinJiang
题目：部落战争 
时间复杂度：O((n*m)^2)
算法：二分图 
思路：一开始每个点都是独立的一条路径，每连接两个点路径就减一，所以答案为总点数减最大匹配*/
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
const int N=1e4;

int n,m,r,c,ans,Map[N],vis[N],match[N];
VI e[N];

int ID(int x,int y){
	return (x-1)*m+y;
}

bool OK(int x,int y){
	if(x<1||y<1||x>n||y>m) return 0;
	if(!Map[ID(x,y)]) return 0;
	return 1;
}

bool find(int u){
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
	cin>>n>>m>>r>>c;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char x;
			cin>>x;
			if(x=='.') Map[ID(i,j)]=1,ans++;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(!Map[ID(i,j)]) continue;
			if(OK(i+r,j+c)) e[ID(i,j)].pb(ID(i+r,j+c));
			if(OK(i+r,j-c)) e[ID(i,j)].pb(ID(i+r,j-c));
			if(OK(i+c,j+r)) e[ID(i,j)].pb(ID(i+c,j+r));
			if(OK(i+c,j-r)) e[ID(i,j)].pb(ID(i+c,j-r));
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(!Map[ID(i,j)]) continue;
			memset(vis,0,sizeof(vis));
			if(find(ID(i,j))) ans--;
		}
	cout<<ans<<endl;
	return 0;
}

