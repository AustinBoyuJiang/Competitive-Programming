/*Author：AustinJiang
题目：The Perfect Stall
时间复杂度：O((n+m)^2)
算法：二分图 
来源：USACO Section 4.2 */
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
const int N=210;

int n,m,ans,vis[N],match[N];
VI e[N];

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
	cin>>n>>m;
	for(int i=1,j,s;i<=n;i++){
		cin>>s;
		while(s--)
		cin>>j,e[i].pb(j);
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(find(i)) ans++;
	}
	cout<<ans<<endl;
	return 0;
}

