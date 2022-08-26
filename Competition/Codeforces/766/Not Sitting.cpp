/*Author：AustinJiang
题目：Not Sitting
时间复杂度：O(t*n*m)
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

int t,n,m,cnt,vis[N],ans[N];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
struct node{int x,y,step;};
deque<node> q;

int ID(int x,int y){
	return (x-1)*m+y;
}

bool check(int x,int y){
	return x>=1&&y>=1&&x<=n&&y<=m&&!vis[ID(x,y)];
}

void bfs(){
	for(auto u:q)
		vis[ID(u.x,u.y)]=1;
	while(!q.empty()){
		node u=q.front();
		q.pop_front();
		ans[++cnt]=u.step;
		for(int i=0;i<4;i++){
			int nx=u.x+dir[i][0];
			int ny=u.y+dir[i][1];
			if(check(nx,ny)){
				q.pb({nx,ny,u.step+1});
				vis[ID(nx,ny)]=1;
			}
		}
	}
}

//void solve(){
//	cin>>n>>m;			
//	cnt=0;
//	memset(vis,0,sizeof(vis));
//	int x=n>>1;
//	int y=m>>1;
//	if(n&1&&m&1){
//		q.pb({x+1,y+1,x+y});
//	}
//	else if(n&1){
//		q.pb({x+1,y,x+y});
//		q.pb({x+1,y+1,x+y});
//	}
//	else if(m&1){
//		q.pb({x,y+1,x+y});
//		q.pb({x+1,y+1,x+y});
//	}
//	else{
//		q.pb({x+1,y,x+y});
//		q.pb({x+1,y+1,x+y});
//		q.pb({x,y+1,x+y});
//		q.pb({x+1,y+1,x+y});
//	}
//	bfs();
//	for(int i=1;i<=cnt;i++)
//		cout<<ans[i]<<' ';
//	cout<<endl;
//}

void solve(){
	cin>>n>>m;
	cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans[++cnt]=max(i-1,n-i)+max(j-1,m-j);
	sort(ans+1,ans+cnt);
	for(int i=1;i<=cnt;i++)
		cout<<ans[i]<<' ';
	cout<<endl;
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

