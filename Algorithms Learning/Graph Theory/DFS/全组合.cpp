/*Author：AustinJiang
题目：全组合
时间复杂度：O(n^m)
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
const int N=20;

int n,m,f[N],vis[N];

void dfs(int x,int pos){
	f[pos]=x;
	if(pos>=m){
		for(int i=1;i<m;i++)
			cout<<f[i]<<' ';
		cout<<f[m]<<endl;
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(i,pos+1);
		vis[i]=0;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	dfs(0,0);
	return 0;
}

