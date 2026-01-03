/*
 * Author: Austin Jiang
 * Date: 7/19/2022 12:44:37 AM
 * Problem:
 * Description:
*/
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl '\n'
#define lc (mid<<1)
#define rc (mid<<1|1)
#define lb lower_bound
#define ub upper_bound
#define PQ priority_queue
#define random(a,b) rand()%(b-a+1)+a
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
using namespace std;
using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<PI>;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

const int N = 50;
int T=1,n,m,k,sx,sy,ex,ey,ans,vis[N][N],Map[N][N];
bool res;

struct wall{
	int x1,x2,y1,y2,flag=0;
} w[N];

bool OK(int x,int y){
	if(x<1||x>n) return 0;
	if(y<1||y>m) return 0;
	if(vis[x][y]) return 0;
	if(Map[x][y]) return 0;
	return 1;
}

void find(int x,int y){
	if(x==ex&&y==ey){
		res=1;
		return;
	}
	vis[x][y]=1;
	rep(i,0,3){
		int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		if(OK(nx,ny)){
			find(nx,ny);
			if(res) return;
		}
	}
}

bool check(){
	rep(i,1,n) rep(j,1,m){
		vis[i][j]=0;
		Map[i][j]=0;
	}
	rep(p,1,k){
		if(!w[p].flag) continue;
		rep(i,w[p].x1,w[p].x2){
			rep(j,w[p].y1,w[p].y2){
				Map[i][j]=1;
			}
		}
	}
	res=0;
	find(sx,sy);
	return res;
}

bool dfs(int pos,int p,int cnt){
	w[pos].flag=p;
	if(pos==k){
		if(!cnt&&check()) return 1;
		return 0;
	}
	if(dfs(pos+1,1,cnt)) return 1;;
	if(cnt) return dfs(pos+1,0,cnt-1);
}

void solve(int Case){
	cin>>n>>m>>k;
	n=n*2+1,m=m*2+1;
	cin>>sx>>sy>>ex>>ey;
	sx=(sx+1)*2,sy=(sy+1)*2;
	ex=(ex+1)*2,ey=(ey+1)*2;
	rep(i,1,k){
		cin>>w[i].x1>>w[i].y1>>w[i].x2>>w[i].y2;
		w[i].x1=w[i].x1*2+1,w[i].x2=w[i].x2*2+1;
		w[i].y1=w[i].y1*2+1,w[i].y2=w[i].y2*2+1;
		if(w[i].x1>w[i].x2) swap(w[i].x1,w[i].x2);
		if(w[i].y1>w[i].y2) swap(w[i].y1,w[i].y2);
	}
	rep(i,0,k-1){
		if(dfs(0,0,i)){
			cout<<i<<endl;
			return;
		}
	}
	cout<<k<<endl;
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
//	freopen("in.txt","r",stdin);
	cin>>T;
	rep(Case,1,T) solve(Case);
	return 0;
}
