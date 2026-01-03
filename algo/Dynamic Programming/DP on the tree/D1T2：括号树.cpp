/*Author：AustinJiang
题目：D1T2：括号树
时间复杂度：O(n)
算法：动态规划，树形DP，DFS 
来源：CSP 2019
思路：f[i]表示以i结尾的合法子串数 
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
const int N=5e5+10;

int n,ans,f[N],fa[N];
char str[N];
stack<int> stk;
VI e[N];

void dfs1(int u){
	int pos=0;
	if(str[u]==')'&&!stk.empty()){
		pos=stk.top();
		stk.pop();
		f[u]=f[fa[pos]]+1;
	}
	if(str[u]=='(') stk.push(u);
	for(auto v:e[u])
		dfs1(v);
	if(str[u]==')'&&pos) stk.push(pos);
	if(str[u]=='(') stk.pop();
}

void dfs2(int u){
	f[u]+=f[fa[u]];
	ans^=u*f[u];
	for(auto v:e[u])
		dfs2(v); 
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>str[i];
	for(int i=2;i<=n;i++){
		cin>>fa[i];
		e[fa[i]].pb(i);
	}
	dfs1(1);
	dfs2(1);
	cout<<ans<<endl;
	return 0;
}

