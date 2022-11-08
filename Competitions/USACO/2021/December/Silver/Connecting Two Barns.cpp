/*Author：AustinJiang
题目：Connecting Two Barns
时间复杂度：O(n)
算法：双指针，连通块 
来源：USACO 2022 December Gold */
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
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=1e5+10;

int t,n,m,f[N],mn1[N],mnn[N];

int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void merge(int x,int y){
	f[find(x)]=find(y);
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		f[i]=i;
		mn1[i]=INF;
		mnn[i]=INF;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		merge(x,y);
	}
	mn1[find(1)]=0;
	mnn[find(n)]=0;
	int lst1=-INF,lstn=-INF;
	for(int i=1;i<=n;i++){
		if(find(i)==find(1)) lst1=i;
		if(find(i)==find(n)) lstn=i;
		mn1[find(i)]=min(mn1[find(i)],i-lst1);
		mnn[find(i)]=min(mnn[find(i)],i-lstn);
	}
	lst1=INF,lstn=INF;
	for(int i=n;i>=1;i--){
		if(find(i)==find(1)) lst1=i;
		if(find(i)==find(n)) lstn=i;
		mn1[find(i)]=min(mn1[find(i)],lst1-i);
		mnn[find(i)]=min(mnn[find(i)],lstn-i);
	}
	int ans=INF;
	for(int i=1;i<=n;i++)
		ans=min(ans,mn1[find(i)]*mn1[find(i)]+mnn[find(i)]*mnn[find(i)]);
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
		solve();
	return 0;
}

