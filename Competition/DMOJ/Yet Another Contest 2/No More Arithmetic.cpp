/*Author：AustinJiang
题目：No More Arithmetic
时间复杂度：O(n^2)
算法：最小生成树 */
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PQ priority_queue
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f;
const int N=2010;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,mod,ans,a[N],c[N],vis[N];

int path(int u,int v){
	int x=max(a[u],a[v]),y=min(a[u],a[v]);
	int res=max(max((x+y)%mod,(x-y)%mod),(x*y)%mod);
	if(x%y==0) res=max(res,(x/y)%mod);
	return res;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>mod;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1,u=-1;i<=n;i++,u=-1){
		for(int j=1;j<=n;j++)
			if(!vis[j]&&(u==-1||c[j]>c[u])) u=j;
		vis[u]=1,ans+=c[u];
		for(int v=1;v<=n;v++)
			if(u!=v) c[v]=max(c[v],path(u,v));
	}
	cout<<ans<<endl;
	return 0;
}
