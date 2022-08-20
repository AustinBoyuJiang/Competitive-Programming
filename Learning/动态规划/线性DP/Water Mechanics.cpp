/*Author：AustinJiang
题目：Water Mechanics
时间复杂度：O(n)
算法：动态规划 
来源：DMOPC '21 Contest 2 P4
思路：dp[i]表示从0到i需要几次 */
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

int n,k,flag,dist,a[N],dp[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[1]=1;
	dist=1;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1];
		if(a[i]>a[i-1]){
			if(flag==2) dp[i]++;
			dist=1;
			flag=1;
		}
		else if(a[i]<a[i-1]){
			dist=1;
			flag=2;
		}
		cout<<dist<<' ';
		if(dist++>k){
			if(flag!=2) flag=2;
			else flag=0,dp[i]++;
			dist=1;
		}
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<dp[i]<<' ';
	}
	cout<<endl;
	cout<<dp[n]<<endl;
	return 0;
}

