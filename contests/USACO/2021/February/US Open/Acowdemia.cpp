/*Author：AustinJiang
题目：Acowdemia
时间复杂度：O(n*log(n))
算法：二分
来源：USACO 2021 Open Contest */
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
const int N=1e5+10;

int n,k,l,c[N];

bool cmp(int a,int b){
	return a>b;
}

bool check(int h){
	int sum=0;
	for(int i=1;i<=h;i++){
		if(c[i]<h){
			sum+=h-c[i];
			if(h-c[i]>k) return 0;
		}
	}
	return sum<=k*l;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k>>l;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	sort(c+1,c+n+1,cmp);
	int l=0,r=n,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}

