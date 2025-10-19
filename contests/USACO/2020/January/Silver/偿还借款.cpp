/*Author：AustinJiang
题目：偿还借款 
时间复杂度：O(log(n)*sqrt(m))
算法：二分，除法分块 
来源：USACO 2020 January Contest, Silver */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define int ll
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

int n,k,m;

bool check(int x){
	int s=k,g=0;
	while(s){
		int y=(n-g)/x;
		if(y<m){
			g+=s*m;
			break;
		}
		else{
			int a=(n-g)/y-x+1;
			g+=min(a,s)*y;
			s-=min(a,s);
		}
	}
	return g>=n;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k>>m;
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}

