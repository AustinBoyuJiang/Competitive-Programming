/*Author：AustinJiang
题目：Anton And Tree
时间复杂度：O()
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
const int N=2e5+10;

int n,tot,co[N],id[N];
VI e[N],ee[N];

void merge(int u,int fa){
	if(co[u]==co[fa]) id[u]=id[fa];
	else{
		id[u]=++tot;
		if(fa){
			ee[id[u]].pb(id[fa]);
			ee[id[fa]].pb(id[u]);
		}
	}
	for(auto v:e[u]){
		if(v==fa) continue;
		merge(v,u);
	}
}

PI dfs(int u,int fa,int dist){
	PI res={dist,u};
	for(auto v:ee[u]){
		if(v==fa) continue;
		res=max(res,dfs(v,u,dist+1));
	}
	return res;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>co[i];
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	co[0]=-1;
	merge(1,0);
	int u=dfs(1,0,1).sec;
	int ans=dfs(u,0,1).fir;
	cout<<ans/2<<endl;
	return 0;
}

