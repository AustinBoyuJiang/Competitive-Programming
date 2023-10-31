/*Author：AustinJiang
题目：N皇后问题
时间复杂度：O(2^8)
算法：DFS */
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
const int N=20;

int n,ans,row[N],col[N],slp1[N],slp2[N];

void dfs(int x,int y){
	if(row[x]) return;
	if(col[y]) return;
	if(slp1[x+y-1]) return;
	if(slp2[n-x+y]) return;
	ans++;
	row[x]=col[y]=slp1[x+y-1]=slp2[n-x+y]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i<=x||j<=y) dfs(i,j);
		}
	}
	row[x]=col[y]=slp1[x+y-1]=slp2[n-x+y]=0;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	dfs(1,1);
	cout<<ans<<endl;
	return 0;
}

