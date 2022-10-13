/*Author：AustinJiang
题目：斜率优化DP
时间复杂度：O(n)
算法：动态规划，斜率优化
来源：HDU3507 */
#pragma GCC optimize(2)
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
const int N=5e5+10;

int n,m,sum[N],dp[N];

bool check1(int j,int k,int i){
	int xk=dp[k]+sum[k]*sum[k],yk=sum[k];
	int xj=dp[j]+sum[j]*sum[j],yj=sum[j];
	return xk-xj<=2*sum[i]*(yk-yj);
}

bool check2(int a,int b,int c){
	int xa=dp[a]+sum[a]*sum[a],ya=sum[a];
	int xb=dp[b]+sum[b]*sum[b],yb=sum[b];
	int xc=dp[c]+sum[c]*sum[c],yc=sum[c];
	return (xb-xa)*(yc-yb)>=(xc-xb)*(yb-ya);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n>>m){
		for(int i=1;i<=n;i++){
			cin>>sum[i];
			sum[i]+=sum[i-1];
		}
		deque<int> q;
		q.pb(0);
		for(int i=1;i<=n;i++){
			while(q.size()>1&&check1(q[0],q[1],i)) q.pop_front();
			int j=q.front();
			dp[i]=dp[j]+(sum[i]-sum[j])*(sum[i]-sum[j])+m;
			while(q.size()>1&&check2(q[q.size()-2],q.back(),i)) q.pop_back();
			q.pb(i);
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}

