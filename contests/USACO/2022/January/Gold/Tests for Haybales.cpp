/*Author：AustinJiang
题目：Tests for Haybales
时间复杂度：O()
算法：
来源：
思路：
*/
#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PI pair<int,int>
#define VI vector<int>
#define VPI vector<PI>
#define PQ priority_queue
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e5+10;

int n,cnt,a[N],x[N],dep[N];
VI e[N];

void dfs(int u,int d){
	x[u]=cnt--;
	dep[u]=d;
	for(auto v:e[u]){
		dfs(v,d+1);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
		e[a[i]+1].pb(i);
	cnt=n+1;
	dfs(n+1,0);
	cout<<n<<endl;
	for(int i=1;i<=n;i++)
		cout<<(dep[1]-dep[i])*n+x[i]<<endl;
	return 0;
}

