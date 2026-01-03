/*Author：AustinJiang
题目：难度计算
时间复杂度：O(n*5)
算法：动态规划 
思路：dp[i]表示长度为i的最小难度 
dp[i]=max(dp[i],dp[i-k]+calc(i-k+1,i)) */
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
const int N=1e5+10;

int n,a[N],dp[N];
char str[N];

bool check1(int l,int r){
	for(int i=l+1;i<=r;i++)
		if(a[i]!=a[i-1]) return 0;
	return 1;
}

bool check2(int l,int r){
	for(int i=l+2;i<=r;i++)
		if(a[i]-a[i-1]!=a[l+1]-a[l]) return 0;
	return a[l+1]-a[l]==1||a[l+1]-a[l]==-1;
}

bool check3(int l,int r){
	for(int i=l+2;i<=r;i++)
		if(a[i]!=a[i-2]) return 0;
	return 1;
}

bool check4(int l,int r){
	for(int i=l+2;i<=r;i++)
		if(a[i]-a[i-1]!=a[l+1]-a[l]) return 0;
	return 1;
}

int calc(int l,int r){
	if(check1(l,r)) return 1;
	if(check2(l,r)) return 2;
	if(check3(l,r)) return 4;
	if(check4(l,r)) return 5;
	return 10;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	cin>>str;
	n=strlen(str);
	for(int i=1;i<=n;i++)
		a[i]=str[i-1]-'0';
	for(int i=3;i<=n;i++)
		for(int j=3;j<=5;j++)
			dp[i]=min(dp[i],dp[i-j]+calc(i-j+1,i));
	cout<<dp[n]<<endl;
	return 0;
}

