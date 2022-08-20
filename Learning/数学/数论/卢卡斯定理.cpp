/*Author：AustinJiang
题目：
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
const int N=1e5+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int t,n,m,p,fact[N];

int inv(int a){
	int b=p-2,ans=1;
	while(b){
		if(b&1) ans*=a,ans%=p;
		a*=a,a%=p;
		b>>=1;
	}
	return ans;
}

int C(int n,int m,int p){
	if(n<m) return 0;
	int ans=1;
	for(int i=n;i>n-m;i--)
		ans=ans*i%p;
	for(int i=1;i<=m;i++)
		ans=ans*inv(i)%p;
	return ans;
}

int lucas(int n,int m,int p){
	if(m==0) return 1;
	return lucas(n/p,m/p,p)*C(n%p,m%p,p)%p;
}

void solve(){
	cin>>n>>m>>p;
	cout<<lucas(n,m,p)<<endl;
}

signed main(){
	cin.tie(NULL)->sync_with_stdio(false);
	cin>>t;
	while(t--)
		solve();
	return 0;
}

