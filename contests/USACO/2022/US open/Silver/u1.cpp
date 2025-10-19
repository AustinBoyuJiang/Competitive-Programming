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

int n,ans,mn,a[N],v[N],vis[N],instk[N];
stack<PI> stk;

void dfs(int u){
	if(vis[u]){
		mn=INF;
		while(!stk.empty()&&stk.top().sec!=u){
			mn=min(mn,stk.top().fir);
			instk[stk.top().sec]=0;
			stk.pop();
		}
		if(!stk.empty()){	
			mn=min(mn,stk.top().fir);
			instk[stk.top().sec]=0;
			stk.pop();
			ans-=mn;
		}
		return;
	}
	vis[u]=1;
	stk.push(mp(v[u],u));
	instk[u]=1;
	dfs(a[u]);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>v[i];
		ans+=v[i];
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		dfs(i);
		while(!stk.empty()){
			instk[stk.top().sec]=0;
			stk.pop();
		}
	}
	cout<<ans<<endl;
	return 0;
}

