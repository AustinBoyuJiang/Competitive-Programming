/*Author：AustinJiang
题目：Farm Updates
时间复杂度：O(n+q)
算法：DFS
来源：USACO 2022 January Gold
思路：正难则反 
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

int n,Q,cnt,id[N],flag[N],ans[N];
VI e[N];

struct query{
	char opt;
	int x,y;
} q[N];

void dfs(int u,int x){
	ans[u]=x;
	for(auto v:e[u]){
		if(ans[v]) continue;
		dfs(v,x);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;i++)
		ans[i]=Q;
	for(int i=1;i<=Q;i++){
		cin>>q[i].opt>>q[i].x;
		if(q[i].opt=='A'){
			cin>>q[i].y;
			id[++cnt]=i;
		}
		if(q[i].opt=='D') ans[q[i].x]=0;
		if(q[i].opt=='R') flag[q[i].x]=1;
	}
	for(int i=1;i<=cnt;i++){
		if(!flag[i]){
			e[q[id[i]].x].pb(q[id[i]].y);
			e[q[id[i]].y].pb(q[id[i]].x);
		}
	}
	for(int i=1;i<=n;i++)
		if(ans[i]) dfs(i,Q);
	for(int i=Q;i>=1;i--){
		if(q[i].opt=='D'&&!ans[q[i].x]) dfs(q[i].x,i-1);
		if(q[i].opt=='R'){
			int x=q[id[q[i].x]].x;
			int y=q[id[q[i].x]].y;
			if(!ans[x]&&ans[y]) dfs(x,i-1);
			if(!ans[y]&&ans[x]) dfs(y,i-1);
			e[x].pb(y);
			e[y].pb(x);
		}
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
	return 0;
}

