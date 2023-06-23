/*Author：AustinJiang
题目：对称二叉树
时间复杂度：O(n^2)
算法：DFS 
来源：NOIP2018 */
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
const int N=1e6+10;

int n,ans=1,flag,val[N],lc[N],rc[N];

int dfs(int x,int y,int tot){
	if(x==-1&&y==-1)  return 0;
	if((x==-1||y==-1&&x!=y)||val[x]!=val[y]){
		flag=0;
		return 0;
	}
	return dfs(lc[x],rc[y],2)+dfs(rc[x],lc[y],2)+tot;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>val[i];
	for(int i=1;i<=n;i++)
		cin>>lc[i]>>rc[i];
	for(int i=1;i<=n;i++){
		flag=1;
		int res=dfs(lc[i],rc[i],3);
		if(flag&&res>ans) ans=res;
	}
	cout<<ans<<endl;
	return 0;
}

