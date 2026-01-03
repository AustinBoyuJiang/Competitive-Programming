/*Author：AustinJiang
题目：Kanna Market
时间复杂度：O(n*log(n))
算法：快速幂 
来源：DMOJ'C21 April Contest*/
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define random(a,b) rand()%(b-a+1)+a
#define PQ priority_queue
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=1e6+10;
const int MOD=1e9+7;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,a[N],b[N],mn[2],mx[2],cnt[2][3];

int pow(int a,int b){
	int res=1;
	while(b){
		if(b&1) res*=a,res%=MOD;
		a*=a,a%=MOD;
		b>>=1;
	}
	return res;
}

int solve(int k){
	int x,y,res=0;
	if(cnt[k][2]) x=mx[k],y=mx[k];
	else if(cnt[k][1]) x=mx[k]+1,y=mn[k]+m;
	else x=2,y=m*2;
	for(int i=x;i<=y;i++){
		if(i<=m) res+=pow(i-1,cnt[k][0]);
		else res+=pow(2*m-i+1,cnt[k][0]);
		res%=MOD;
	}
	return res;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	mn[0]=mn[1]=INF;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++){
		cnt[i&1][(a[i]!=0)+(b[i]!=0)]++;
		if(a[i]+b[i]){
			mn[i&1]=min(mn[i&1],a[i]+b[i]);
			mx[i&1]=max(mx[i&1],a[i]+b[i]);
		}
	}
	cout<<(solve(0)*solve(1))%MOD<<endl;
	return 0;
}

