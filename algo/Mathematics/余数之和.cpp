/*Author：AustinJiang
题目：余数之和
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
const int N=1e5+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,k,ans;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	if(n>k){
		ans+=(n-k)*k;
		n=k;
	}
	int a=1;
	while(a<=n){ //k=a*b+c
		int b=k/a;
		int c=k-a*b;
		int nxt=min(n,k/b)+1;
		int m=nxt-a;
		ans+=c*m-b*(m*(m-1)/2);
		a=nxt;
	}
	cout<<ans<<endl;
	return 0;
}

