/*Author：AustinJiang
题目：牛为什么过马路3
时间复杂度：O(n*log(n))
算法：贪心 
来源：USACO 2017 February Bronze */
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
const int N=110;

int n,ans;
PI q[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>q[i].fir>>q[i].sec;
	sort(q+1,q+n+1);
	for(int i=1;i<=n;i++)
		ans=max(ans,q[i].fir)+q[i].sec;
	cout<<ans<<endl;
	return 0;
}

