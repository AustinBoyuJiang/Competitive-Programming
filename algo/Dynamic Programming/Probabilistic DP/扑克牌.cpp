/*Author：AustinJiang
题目：扑克牌
时间复杂度：O()
算法：
来源：
思路：
*/
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PQ priority_queue
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f;
const int N=15;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int A,B,C,D,vis[N][N][N][N][5][5];
double dp[N][N][N][N][5][5];

double dfs(int a,int b,int c,int d,int x,int y){
	if(vis[a][b][c][d][x][y]) return dp[a][b][c][d][x][y];
	vis[a][b][c][d][x][y]=1;
	int ad=a+(x==1)+(y==1);
	int bd=b+(x==2)+(y==2);
	int cd=c+(x==3)+(y==3);
	int dd=d+(x==4)+(y==4);
	double &ans=dp[a][b][c][d][x][y]=0;
	if(ad>=A&&bd>=B&&cd>=C&&dd>=D) return 0;
	int tot=54-ad-bd-cd-dd;
	if(tot<=0) return 55;
	if(a<13) ans+=dfs(a+1,b,c,d,x,y)*(13-a)/tot;
	if(b<13) ans+=dfs(a,b+1,c,d,x,y)*(13-b)/tot;
	if(c<13) ans+=dfs(a,b,c+1,d,x,y)*(13-c)/tot;
	if(d<13) ans+=dfs(a,b,c,d+1,x,y)*(13-d)/tot;
	if(!x) ans+=min(dfs(a,b,c,d,1,y),min(dfs(a,b,c,d,2,y),min(dfs(a,b,c,d,3,y),dfs(a,b,c,d,4,y))))/tot;
	if(!y) ans+=min(dfs(a,b,c,d,x,1),min(dfs(a,b,c,d,x,2),min(dfs(a,b,c,d,x,3),dfs(a,b,c,d,x,4))))/tot;
	return ++ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>A>>B>>C>>D;
	double ans=dfs(0,0,0,0,0,0);
	if(ans>54) ans=-1;
	printf("%.3lf",ans);
	return 0;
}

