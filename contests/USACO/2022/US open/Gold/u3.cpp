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

int t,b,n,ans,mn[N],mx[N],f[N],l[N],r[N],s[N];
VI e[N];

void dfs(int u,int fa){
	mn[u]=mn[fa],mx[u]=mx[fa];
	if(r[u]<mn[u]) mn[u]=r[u],s[u]=r[u];
	else if(l[u]>mx[u]) mx[u]=l[u],s[u]=l[u];
	else if(l[u]>=mn[u]&&l[u]<=mx[u]) s[u]=l[u];
	else if(r[u]>=mn[u]&&r[u]<=mx[u]) s[u]=r[u];
	else s[u]=mx[u];
	ans=max(ans,mx[u]-mn[u]);
	for(auto v:e[u])
		dfs(v,u);
}

int check(int x){
	if(x<l[1]) return INF;
	if(x>r[1]) return INF;
	mn[1]=mx[1]=x;
	ans=0;
	dfs(1,1);
	return ans;
}

void solve(){
	cin>>n;
	f[1]=1;
	for(int i=1;i<=n;i++)
		e[i].clear();
	for(int i=2;i<=n;i++){
		cin>>f[i];
		e[f[i]].pb(i);
	}
	for(int i=1;i<=n;i++)
		cin>>l[i]>>r[i];
	int L=l[1],R=r[1],ans;
	while(L<=R){
		int mid=L+R>>1;
		if(check(mid)<=check(mid-1)){
			ans=mid;
			L=mid+1;
		}
		else R=mid-1;
	}
	cout<<check(ans)<<endl;
	if(b){
		for(int i=1;i<n;i++)
			cout<<s[i]<<" ";
		cout<<s[n]<<endl;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t>>b;
	while(t--)
		solve();
	return 0;
}

