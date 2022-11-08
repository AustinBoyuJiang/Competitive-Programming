/*Author：AustinJiang
题目：Modern Art 3
时间复杂度：O(n^3)
算法：区间dp 
来源：USACO 2021 February */
#pragma GCC optimize(2)
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
const int N=310;

int n,a[N],dp[N][N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<=n;i++){
		for(int l=1;l+i-1<=n;l++){
			int r=l+i-1;
			if(a[l]==a[r]) dp[l][r]=max(dp[l][r],dp[l+1][r-1]+1);
			for(int k=l+1;k<r-1;k++)
				dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);
		}
	}
	cout<<n-dp[1][n]<<endl;
	return 0;
}

