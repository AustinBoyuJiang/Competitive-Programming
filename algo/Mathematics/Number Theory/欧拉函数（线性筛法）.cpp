/*Author：AustinJiang
题目：欧拉函数 
时间复杂度：O()
算法：
来源：
思路：
*/
//#pragma GCC optimize(2)
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
const int N=1e5;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,tot,phi[N],prime[N];
bool isPrime[N];

signed main(){
	cin.tie(NULL)->sync_with_stdio(false);
	memset(isPrime,1,sizeof(isPrime));
	phi[1]=1,isPrime[1]=0;
	for(int i=2;i<N;i++){
		if(isPrime[i]){
			prime[++tot]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=tot&&i*prime[j]<N;j++){
			isPrime[i*prime[j]]=0;
			if(i%prime[j])
				phi[i*prime[j]]=phi[i]*phi[prime[j]];
			else{
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
		}
	}
	cin>>m;
	while(m--){
		cin>>n;
		cout<<phi[n]<<endl;
	}
	return 0;
}

