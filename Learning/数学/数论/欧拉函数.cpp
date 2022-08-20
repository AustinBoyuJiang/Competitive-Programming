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

int n; 

int euler_phi(int n){
	int ans=n;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			ans=ans/i*(i-1);
			while(n%i==0) n/=i;
		}
	}
	if(n>1) ans=ans/n*(n-1);
	return ans;
}
 
signed main(){
	cin.tie(NULL)->sync_with_stdio(false);
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		cout<<euler_phi(x)<<endl;
	}
	return 0;
}

