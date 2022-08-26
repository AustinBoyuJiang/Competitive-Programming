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

int n,m,x,cnt,pho[N],flag[N];
VI e[N],ee[N];

int dfs1(int u,int fa){//剪枝，新树的边数 
	flag[u]=pho[u];
	int cnt=0;
	for(auto v:e[u]){
		if(v==fa) continue;
		cnt+=dfs1(v,u);
		if(flag[v]){
			ee[u].pb(v);
			flag[u]=1;
			cnt++;
		}
	}
	return cnt;
}

PI dfs2(int u,int fa){//新树的直径 
	int ans=0,mx=0,cmx=0;
	for(auto v:ee[u]){
		if(v==fa) continue;
		PI son=dfs2(v,u);
		ans=max(ans,son.sec);
		cmx=max(cmx,min(mx,son.fir+1));
		mx=max(mx,son.fir+1);
	}
	ans=max(ans,mx+cmx);
	return mp(mx,ans);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x;
		pho[x]=1;
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	cout<<dfs1(x,x)*2-dfs2(x,x).sec<<endl;
	return 0;
}

