/*Author：AustinJiang
题目：度度熊与排列
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
const int N=100;

int t,n,m,res[N][N],flag[N][N],vis[N],match[N],ans[N];
string s[N][2];

bool dfs(int u){
	if(vis[u]) return 1;
	vis[u]=0;
	for(int v=1;v<=m;v++){
		if(res[u][v]&&(!match[v]||dfs(match[v]))){
			match[v]=u;
			return 1;
		}
	}
	return 0;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			res[i][j]=1;
	for(int i=1;i<=n;i++){
		memset(flag,0,sizeof(flag));
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++)
				if(s[i][0][j-1]==s[i][1][k-1])
					flag[j][k]=1;
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++)
				res[j][k]&=flag[j][k];
	}
	memset(match,0,sizeof(match));
	for(int i=m;i>=1;i--){
		memset(vis,0,sizeof(vis));
		if(!dfs(i)){
			cout<<-1<<endl;
			return;
		}
	}
	for(int i=1;i<=m;i++)
		ans[match[i]]=i;
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	cout<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
		solve();
	return 0;
}

