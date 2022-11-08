/*Author：AustinJiang
题目：Not Assigning
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

int t,n,res,ans[N];
VPI e[N];

void dfs(int u,int fa,int p){
	if(e[u].size()>=3){
		res=0;
		return;
	}
	for(auto i:e[u]){
		int v=i.fir;
		if(v==fa) continue;
		p^=1;
		ans[i.sec]=p;
		dfs(v,u,p);
		if(!res) return;
	}
}

void solve(){
	cin>>n;
	res=1;
	for(int i=1;i<=n;i++)
		e[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].pb(mp(v,i));
		e[v].pb(mp(u,i));
	}
	dfs(1,0,0);
	if(!res) cout<<-1<<endl;
	else{
		for(int i=1;i<n;i++){
			if(ans[i]) cout<<2<<" ";
			else cout<<3<<" ";
		}
		cout<<endl;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
		solve();
	return 0;
}

