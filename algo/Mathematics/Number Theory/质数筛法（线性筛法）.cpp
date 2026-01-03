/*Author：AustinJiang
题目：
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

int n,isPrime[N],low[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	fill(isPrime,isPrime+N,1);
	isPrime[0]=isPrime[1]=0;
	VI primes;
	for(int i=2;i<N;i++){
		if(isPrime[i]){
			primes.pb(i);
			low[i]=i;
		}
		for(int x:primes){
			if(i*x>=N) break;
			isPrime[i*x]=0;
			low[i*x]=x;
			if(i%x==0) break;
		}
	}
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		cout<<(isPrime[x]?"YES":"NO")<<endl;
	}
	return 0;
}

