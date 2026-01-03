/*Author：AustinJiang
题目：迷宫逃离 
时间复杂度：O(n)
算法：概率期望dp 
来源：HDU4035 The 36th ACM/ICPC Asia Regional Chengdu Site ―― Online Contest
思路：
*/
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define random(a,b) rand()%(b-a+1)+a
#define PQ priority_queue
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f;
const int N=1010;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int t,n;
double k[N],e[N],A[N],B[N],C[N];
VI ee[N];

void dfs(int u,int fa){
	int m=ee[u].size();
	double totA=0,totB=0,totC=0;
	for(auto v:ee[u]){
		if(v==fa) continue;
		dfs(v,u);
		totA+=A[v];
		totB+=B[v];
		totC+=C[v];
	}
	A[u]=(k[u]+(1-k[u]-e[u])/m*totA)/(1-(1-k[u]-e[u])/m*totB);
	B[u]=(1-k[u]-e[u])/m/(1-(1-k[u]-e[u])/m*totB);
	C[u]=((1-k[u]-e[u])+(1-k[u]-e[u])/m*totC)/(1-(1-k[u]-e[u])/m*totB);
}

void solve(int Case){
	cin>>n;
	for(int i=1;i<=n;i++)
		ee[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		ee[u].pb(v);
		ee[v].pb(u);
	}
	for(int i=1;i<=n;i++){
		cin>>k[i]>>e[i];
		k[i]/=100;
		e[i]/=100;
	}
	dfs(1,0);
	printf("Case %d: ",Case);
	if(A[1]==1) printf("impossible\n");
	else{
		double ans=C[1]/(1-A[1]);
		printf("%.6lf\n",ans);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++)
		solve(i);
	return 0;
}

