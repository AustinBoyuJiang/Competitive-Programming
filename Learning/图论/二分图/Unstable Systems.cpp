/*Author：AustinJiang
题目：Unstable Systems
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
const int N=510;

int n,a[N][N],vis[N],match[N];

bool dfs(int u,int x){
	if(vis[u]) return 0;
	vis[u]=1;
	for(int v=1;v<=n;v++){
		if(a[u][v]>x) continue;
		if(!match[v]){
			match[v]=u;
			return 1;
		}
		else if(dfs(match[v],x)){
			match[v]=u;
			return 1;
		}
	}
	return 0;
}

bool check(int x){
	memset(match,0,sizeof(match));
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(!dfs(i,x)) return 0;
	}
	return 1;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int l=INF,r=-INF,ans;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			l=min(l,a[i][j]);
			r=max(r,a[i][j]);
		}
	}
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans<<endl;
	check(ans);
	for(int i=1;i<=n;i++)
		cout<<match[i]<<' '<<i<<endl;
	return 0;
}

