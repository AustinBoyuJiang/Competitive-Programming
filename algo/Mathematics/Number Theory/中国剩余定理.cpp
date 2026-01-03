/*Author：AustinJiang
题目：中国剩余定理
时间复杂度：O()
算法：
来源：
思路：
*/
//#pragma GCC optimize(2)
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
const int INF=0x3f3f3f3f;
const int N=110;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,sum,mod=1,a[N],b[N];

void exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		mod*=a[i];
	}
	for(int i=1;i<=n;i++){
		int x,y,m=mod/a[i];
		exgcd(m,a[i],x,y);
		sum+=b[i]*m*x;
	}
	cout<<(sum-(sum-mod+1)/mod*mod)%mod<<endl;
	return 0;
}

