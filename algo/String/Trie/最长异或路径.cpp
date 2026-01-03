/*Author：AustinJiang
题目：最长异或路径 
时间复杂度：O(n*log(n))
算法：字典树，DFS */
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

int n,tot,ans,a[N],trie[N*32][32];
VPI e[N];

void insert(int x){
	int u=0;
	for(int i=31;i>=0;i--){
		int d=x>>i&1;
		if(!trie[u][d]) trie[u][d]=++tot;
		u=trie[u][d];
	}
}

int find(int x){
	int u=0,res=0;
	for(int i=31;i>=0;i--){
		int d=x>>i&1;
		if(trie[u][!d]){
			u=trie[u][!d];
			res=res<<1|1;
		}
		else{
			u=trie[u][d];
			res=res<<1;
		}
	}
	return res;
}

void dfs(int u,int fa,int dist){
	insert(a[u]=dist);
	for(auto i:e[u]){
		if(fa==i.fir) continue;
		dfs(i.fir,u,dist^i.sec);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].pb(mp(v,w));
		e[v].pb(mp(u,w));
	}
	dfs(1,0,0);
	for(int i=1;i<=n;i++)
		ans=max(ans,find(a[i]));
	cout<<ans<<endl;
	return 0;
}

