/*Author：AustinJiang
题目：
时间复杂度：O()
算法：
来源：
思路：
*/
#pragma GCC optimize(2)
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
const int N=3e6+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,p,inv[N];

//inv(x)=pow(x,p-2)

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>p;
	inv[1]=1;
	cout<<inv[1]<<endl;
	for(int i=2;i<=n;i++){
		inv[i]=(p-p/i)*inv[p%i]%p;
		cout<<inv[i]<<endl;
	}
	return 0;
}

