/*Author：AustinJiang
题目：New Year's Problem
时间复杂度：O(t*log(maxa)*m*n)
算法：
来源：
思路：
*/
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
const int N=1e5+10;

int t,m,n,flag[N];
VI a[N];

bool check(int x){
	for(int i=1;i<=n;i++)
		flag[i]=0;
	bool res=0;
	for(int i=1;i<=m;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]>=x){
				flag[j]=1;
				cnt++;
			}
		}
		if(cnt>=2) res=1;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]) res=0;
	}
	return res;
}

void solve(){
	int l=1,r=1,ans;;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		a[i].clear();
		a[i].pb(0);
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			a[i].pb(x);
			r=max(r,x);
		}
	}
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

