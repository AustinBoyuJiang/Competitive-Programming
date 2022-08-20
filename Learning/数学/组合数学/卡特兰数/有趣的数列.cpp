/*Author：AustinJiang
题目：
时间复杂度：O()
算法：
来源：
思路：
*/
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
const int N=2e6+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,p,tot,ans=1,low[N],prime[N],notPrime[N],cnt[N];

void init(){
	notPrime[0]=notPrime[1]=1;
	for(int i=2;i<N;i++){
		if(!notPrime[i]){
			prime[++tot]=i;
			low[i]=i;
		}
		for(int j=1;j<=tot&&i*prime[j]<N;j++){
			notPrime[i*prime[j]]=1;
			low[i*prime[j]]=prime[j];
			if(i%prime[j]==0) break;
		}
	}
}

void add(int x,int k){
	while(x!=1){
		cnt[low[x]]+=k;
		x/=low[x];
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>p;
	init();
	for(int i=n+1;i<=n*2;i++) add(i,1);
	for(int i=1;i<=n+1;i++) add(i,-1);
	for(int i=1;i<=tot;i++){
		for(int j=1;j<=cnt[prime[i]];j++){
			ans*=prime[i];
			ans%=p;
		}
	}
	cout<<ans<<endl;
	return 0;
}
