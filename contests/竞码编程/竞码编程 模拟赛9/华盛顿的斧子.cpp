/*Author：AustinJiang
题目：
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
const int N=1e5+10;

int n,m,ans,flag[N];
VPI e[N];

int dfs(int u,int fa,int w){
	int tot=0,mx=0,cnt=0;
	for(auto i:e[u]){
		int v=i.fir;
		if(v==fa) continue;
		int x=dfs(v,u,i.sec);
		if(flag[v]){
			flag[u]=1;
			tot+=x;
			mx=max(mx,x);
			cnt++;
		}
	}
//	cout<<u<<' '<<flag[u]<<' '<<cnt<<' '<<tot<<endl;
	if(!cnt&&flag[u]) return w;
	else if(cnt&&flag[u]){
		ans+=tot;
		return w;
	}
	else if(!cnt&&!flag[u]){
		return 0;
	}
	else{
		if(e[u].size()>(u==0?0:1)){	
			ans+=tot-mx;
			return min(mx,w);
		}
		else{
			return min(mx,w);
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].pb(mp(v,w));
		e[v].pb(mp(u,w));
	}
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		flag[x]=1;
	}
	dfs(0,-1,0);
	cout<<ans<<endl;
	return 0;
}

