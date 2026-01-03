/*Author：AustinJiang
题目：联合内阁 
时间复杂度：O(n*sum(a))
算法：动态规划
思路：dp[i]表示能否到达i */
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
const int N=500;
const int SUM=1e5+10;

int n,sum,ans,a[N];
bool dp[SUM];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=n;i>=1;i--){ //从大到小保证当前最小 
		for(int j=sum/2;j>=0;j--){ //从大到小保证当前这轮不会互相影响 
			if(dp[j]){
				dp[j+a[i]]=1;
				ans=max(ans,j+a[i]); 
			}
		} 
	}
	cout<<ans<<endl;
	return 0;
}

