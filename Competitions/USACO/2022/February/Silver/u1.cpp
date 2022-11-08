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
const int N=1e3;

int n,a[N][N],id[N],vis[N];

bool dfs(int i){
	if(vis[i]) return 0;
	vis[i]=1;
	for(int j=1;j<=n;j++){
		if(a[i][j]==i) return 0;
		if(!id[a[i][j]]){
			id[a[i][j]]=i;
			return 1;
		}
		else{
			if(dfs(id[a[i][j]])){
				id[a[i][j]]=i;
				return 1;
			}
		}
	}
}

bool check(int i,int j){
	id[i]=0;
	if(dfs(id[a[i][j]])) return 1;
	id[i]=i;
	return 0;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=n;i++)
			id[i]=i;
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=n;j++){
			if(a[i][j]==i||check(i,j)){
				cout<<a[i][j]<<endl;
				break;
			}
		}
	}
	return 0;
}

