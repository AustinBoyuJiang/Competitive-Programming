/*Author：AustinJiang
题目：二维树状数组 
时间复杂度：O(q*log(n)*log(m))
算法：树状数组，差分*/
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
const int N=3e3;

int n,m,d[N][N][4];
char opt;

int lowbit(int x){
	return x&-x;
}

void update(int x,int y,int v){
	for(int i=x;i<=n;i+=lowbit(i)){
		for(int j=y;j<=m;j+=lowbit(j)){
			d[i][j][0]+=v;
			d[i][j][1]+=v*x;
			d[i][j][2]+=v*y;
			d[i][j][3]+=v*x*y;
		}
	}
}

int query(int x,int y,int k){
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			ans+=d[i][j][k];
	return ans;
}

int get_sum(int x,int y){
	return (x*y+x+y+1)*query(x,y,0)-(y+1)*query(x,y,1)-(x+1)*query(x,y,2)+query(x,y,3);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>opt>>n>>m;
	while(cin>>opt){
		int a,b,c,d,x;
		cin>>a>>b>>c>>d;
		if(opt=='L') cin>>x,update(a,b,x),update(a,d+1,-x),update(c+1,b,-x),update(c+1,d+1,x);
		else cout<<get_sum(c,d)-get_sum(a-1,d)-get_sum(c,b-1)+get_sum(a-1,b-1)<<endl;
	}
	return 0;
}

