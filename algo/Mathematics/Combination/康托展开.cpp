/*Author：AustinJiang
题目：
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
const int N=12;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,a[N],fact[N];

int get(int x){
	int ans=a[x];
	for(int i=1;i<=x;i++)
		if(a[i]<=a[x]) ans--;
	return ans;
}

int solve(){
	int ans=1;
	for(int i=1;i<=10;i++){
		char x;
		cin>>x;
		a[i]=x-'A'+1;
		ans+=get(i)*fact[10-i];
	}
	return ans;
}

signed main(){
	cin.tie(NULL)->sync_with_stdio(false);
	fact[0]=1;
	for(int i=1;i<=10;i++)
		fact[i]=fact[i-1]*i;
	cin>>n;
	while(n--)
		cout<<solve()<<endl; 
	return 0;
}

