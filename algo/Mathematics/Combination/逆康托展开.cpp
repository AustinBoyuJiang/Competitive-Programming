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
const int N=20;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,a[N],fact[N],flag[N];

int get(int x){
	for(int i=1;i<=m;i++){
		if(!flag[i]) x--;
		if(x==-1){
			flag[i]=1;
			return i;
		}
	}
}

signed main(){
	cin.tie(NULL)->sync_with_stdio(false);
	cin>>n>>m;
	n--;
	fact[0]=1;
	for(int i=1;i<=m;i++)
		fact[i]=fact[i-1]*i;
	for(int i=1;i<=m;i++){
		a[i]=n/fact[m-i];
		n%=fact[m-i];
	}
	for(int i=1;i<=m;i++)
		cout<<(char)('A'+get(a[i])-1)<<" ";
	return 0;
}

