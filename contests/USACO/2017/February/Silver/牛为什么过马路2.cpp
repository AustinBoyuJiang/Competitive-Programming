/*Author：AustinJiang
题目：牛为什么过马路2
时间复杂度：O(n)
算法：前缀和，枚举 
来源：USACO 2017 February Silver */
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

int n,k,b,ans=INF,cnt[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k>>b;
	for(int i=1;i<=b;i++){
		int id;
		cin>>id;
		cnt[id]=1;
	}
	for(int i=1;i<=n;i++)
		cnt[i]+=cnt[i-1];
	for(int i=k;i<=n;i++)
		ans=min(ans,cnt[i]-cnt[i-k]);
	cout<<ans<<endl;
	return 0;
}

