/*Author: AustinJiang
题目: 理想的正方形
时间复杂度: O(n*n*log(n))
算法: RMQ,ST表*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PI pair<int, int>
#define VI vector<int>
using namespace std;
const int INF=INT_MAX;
const int N=1e3+10;

//mx[i][j][k]表示从(i,j)开始长度为2的k次方的正方形的最大值
int a,b,n,x,ans=INF,mx[N][N][10],mn[N][N][10];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>n;
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++){
			cin>>x;
			mx[i][j][0]=mn[i][j][0]=x;
		}
	for(int k=1;1<<k<=n;k++)
		for(int i=1;i+(1<<k)-1<=a;i++)
			for(int j=1;j+(1<<k)-1<=b;j++){
				mx[i][j][k]=max(mx[i][j][k-1],max(mx[i+(1<<k-1)][j][k-1],max(mx[i][j+(1<<k-1)][k-1],mx[i+(1<<k-1)][j+(1<<k-1)][k-1])));
				mn[i][j][k]=min(mn[i][j][k-1],min(mn[i+(1<<k-1)][j][k-1],min(mn[i][j+(1<<k-1)][k-1],mn[i+(1<<k-1)][j+(1<<k-1)][k-1])));
			}
	int k=log2(n);
	for(int i=1;i<=a-n+1;i++)
		for(int j=1;j<=b-n+1;j++){
			int Max=max(mx[i][j][k],max(mx[i+n-(1<<k)][j][k],max(mx[i][j+n-(1<<k)][k],mx[i+n-(1<<k)][j+n-(1<<k)][k])));
			int Min=min(mn[i][j][k],min(mn[i+n-(1<<k)][j][k],min(mn[i][j+n-(1<<k)][k],mn[i+n-(1<<k)][j+n-(1<<k)][k])));
			ans=min(ans,Max-Min);
		}
	cout<<ans<<endl;
	return 0;
}

