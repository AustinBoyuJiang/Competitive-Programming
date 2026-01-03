/*Author：AustinJiang
题目：Maze Tac Toe
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
const int N=30;
const int STATUS=2e4;

int n,ans,stx,sty,Map[N][N],vis[N][N][STATUS],flag[STATUS],dig[10];
int dir[4][2]={{1,0},{0,1},{0,-1},{-1,0}};

struct position{
	int	t,x,y;
} pos[N][N];

struct status{
	int x,y,k;
};

bool ok(int x,int y){
	if(Map[x][y]) return 0;
	if(x<1||x>n) return 0;
	if(y<1||y>n) return 0;
	return 1;
}

void init(int k){
	memset(dig,0,sizeof(dig));
	int cnt=0;
	while(k){
		dig[++cnt]=k%3;
		k/=3;
	}
}

int add(int k,int x,int y){
	if(!pos[x][y].t) return k;
	init(k);
	int dx=pos[x][y].x;
	int dy=pos[x][y].y;
	if(dig[(dx-1)*3+dy]) return k;
	dig[(dx-1)*3+dy]=pos[x][y].t;
	int res=0;
	for(int i=9;i>=1;i--){
		res*=3;
		res+=dig[i];
	}
	return res;
}

int win(int a,int b,int c){
	return dig[a]==1&&dig[b]==2&&dig[c]==2;
}

bool check(int k){
	init(k);
	if(win(1,2,3)) return 1;
	if(win(4,5,6)) return 1;
	if(win(7,8,9)) return 1;
	if(win(3,2,1)) return 1;
	if(win(6,5,4)) return 1;
	if(win(9,8,7)) return 1;
	if(win(1,4,7)) return 1;
	if(win(2,5,8)) return 1;
	if(win(3,6,9)) return 1;
	if(win(7,4,1)) return 1;
	if(win(8,5,2)) return 1;
	if(win(9,6,3)) return 1;
	if(win(1,5,9)) return 1;
	if(win(9,5,1)) return 1;
	if(win(3,5,7)) return 1;
	if(win(7,5,3)) return 1;
	return 0;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		string row;
		cin>>row;
		for(int j=1;j<=n;j++){
			string cell=row.substr((j-1)*3,3);
			if(cell=="###")
				Map[i][j]=1;
			else if(cell=="BBB"){
				stx=i;
				sty=j;
			}
			else if(cell!="..."){
				pos[i][j].t=(cell[0]=='O')+1;
				pos[i][j].x=cell[1]-'0';
				pos[i][j].y=cell[2]-'0';
			}
		}
	}
	queue<status> q;
	q.push({stx,sty,0});
	while(!q.empty()){
		status now=q.front(); q.pop();
		if(vis[now.x][now.y][now.k]) continue;
		vis[now.x][now.y][now.k]=1;
		if(check(now.k)){
			if(!flag[now.k]){
				ans++;
				flag[now.k]=1;
			}
			continue;
		}
		for(int i=0;i<4;i++){
			int nx=now.x+dir[i][0];
			int ny=now.y+dir[i][1];
			if(ok(nx,ny)){
				int nk=add(now.k,nx,ny);
				q.push({nx,ny,nk});
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

