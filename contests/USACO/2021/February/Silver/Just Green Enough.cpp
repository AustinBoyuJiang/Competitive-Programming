/*Author：AustinJiang
题目：Just Green Enough
时间复杂度：O(n^3)
算法：枚举 
来源：USACO 2021 February Silver */
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
const int N=510;

int n,ans,v[N][N],f[N][N],s[N];

int solve(){
	int res=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) s[j]=1;
		for(int j=i;j<=n;j++){
			int cnt=0;
			for(int k=1;k<=n;k++){
				s[k]&=f[j][k];
				if(s[k]) res+=++cnt;
				else cnt=0;
			}
		}
	}
	return res;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>v[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=v[i][j]>=100;
	ans+=solve();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=v[i][j]>100;
	ans-=solve();
	cout<<ans<<endl;
	return 0;
}

