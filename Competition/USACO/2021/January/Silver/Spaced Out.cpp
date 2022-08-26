/*Author：AustinJiang
题目：Spaced Out
时间复杂度：O(n^2)
来源：USACO 2021 January Contest, Silver */
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
const int N=1e3+10;

int n,ans[2],v[N][N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>v[i][j];
	for(int i=1;i<=n;i++){
		int sum[2][2]={{0,0},{0,0}};
		for(int j=1;j<=n;j++){
			sum[0][j&1]+=v[i][j];
			sum[1][j&1]+=v[j][i];
		}
		ans[0]+=max(sum[0][0],sum[0][1]);
		ans[1]+=max(sum[1][0],sum[1][1]);
	}
	cout<<max(ans[0],ans[1])<<endl;
	return 0;
}

