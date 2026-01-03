/*Author：AustinJiang
题目：sort
时间复杂度：O()
算法：
来源：
思路：
*/
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
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int m,n,ans,a[5][N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("sort.in","r",stdin);
//	freopen("sort.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int mx=-INF,mn=INF;
			for(int k=1;k<=m;k++){
				mx=max(mx,a[k][i]+a[k][j]);
				mn=min(mn,a[k][i]+a[k][j]);
			}
			ans+=mx+mn;
		}
	}
	cout<<ans<<endl;
	return 0;
}

