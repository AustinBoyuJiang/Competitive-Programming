/*Author：AustinJiang
题目：可乐 
时间复杂度：O(n^2*log(t))
算法：矩阵快速幂 
来源：TJOI2017 */
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
const int MOD=2017;

int n,m,t,ans,sum[N][N],a[N][N],b[N][N];

void muti(int a[N][N],int b[N][N]){
	int res[N][N];
	memset(res,0,sizeof(res));
	for(int i=1;i<=n*2;i++)
		for(int j=1;j<=n*2;j++)
			for(int k=1;k<=n*2;k++)
				res[i][j]+=a[i][k]*b[k][j],res[i][j]%=MOD;
	for(int i=1;i<=n*2;i++)
		for(int j=1;j<=n*2;j++)
			a[i][j]=res[i][j];
}


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		a[u][v]=1;
		a[v][u]=1;
	}
	cin>>t;
	b[1][1]=1;
	for(int i=1;i<=n;i++){
		a[i][i]=1;
		a[i+n][i]=1;
		a[i+n][i+n]=1;
		sum[i][i]=1;
		sum[i+n][i+n]=1;
	}
	while(t){
		if(t&1) muti(sum,a);
		muti(a,a);
		t>>=1;
	}
	muti(sum,b);
	for(int i=1;i<=n*2;i++)
		ans+=sum[i][1];
	cout<<ans%MOD<<endl;
	return 0;
}

