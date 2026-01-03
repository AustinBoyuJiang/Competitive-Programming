/*Author：AustinJiang
题目：Stable Arrangement of Rooks
时间复杂度：O()
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

int t,n,k,res,a[50][50],row[50],col[50],dir[4][2]={{2,2},{2,-2},{-2,2},{-2,-2}};

void dfs(int x,int y,int cnt){
	a[x][y]=1;
	row[x]=row[x+1]=row[x-1]=1;
	col[y]=col[y+1]=col[y-1]=1;
	if(cnt==k){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]) cout<<"R";
				else cout<<".";
			}
			cout<<endl;
		}
		res=1;
		return;
	}
	else{
		for(int i=0;i<4;i++){
			int nx=x+dir[i][0];
			int ny=y+dir[i][1];
			if(nx>=1&&ny>=1&&nx<=n&&ny<=n&&!row[nx]&&!col[ny]){
				dfs(nx,ny,cnt+1);
				if(res) return;
			}
		}
	}
}

void solve(){
	memset(a,0,sizeof(a));
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	cin>>n>>k;
	if((n+1)/2<k) cout<<-1<<endl;
	else{
		res = 0;
		dfs(1,1,1);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
		solve();
	return 0;
}

