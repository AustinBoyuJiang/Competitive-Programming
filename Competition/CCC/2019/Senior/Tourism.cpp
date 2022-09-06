/*Author：AustinJiang
题目：Tourism
时间复杂度：O(n*k*log(k))
算法：线段树，动态规划 
来源：CCC 2019 Senior 
思路：dp[i][j]表示第i天偷了j次懒
*/
#include<bits/stdc++.h>
#define int long long
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
const int N=1e5+10;
const int K=100;

int n,p,m,tot,a[N],dp[N][K],mx[N*4];

void build(int rt,int l,int r){
	if(l==r){
		mx[rt]=a[++tot];
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	mx[rt]=max(mx[rt*2],mx[rt*2+1]);
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return mx[rt];
	int mid=(l+r)/2;
	if(y<=mid) return query(rt*2,l,mid,x,y);
	else if(x>mid) return query(rt*2+1,mid+1,r,x,y);
	else return max(query(rt*2,l,mid,x,mid),query(rt*2+1,mid+1,r,mid+1,y));
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>p;
	m=ceil((double)n/p);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	for(int i=1;i<=m;i++){//天数 
		for(int j=0;j<=m*p-n;j++){//总共偷懒的
			for(int k=0;k<=j;k++){//今天偷懒的
				int x=max(1ll,(i-1)*p-(j-k)+1);
				int y=min(n,i*p-j);
//				int num=0;
//				for(int l=x;l<=y;l++){
//					num=max(num,a[l]);
//				}
//				dp[i][j]=max(dp[i][j],dp[i-1][j-k]+num);
				dp[i][j]=max(dp[i][j],dp[i-1][j-k]+query(1,1,n,x,y));
			}
		}
	}
	cout<<dp[m][m*p-n]<<endl;
	return 0;
}

