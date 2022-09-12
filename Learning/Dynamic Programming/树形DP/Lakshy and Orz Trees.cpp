/*Author: AustinJiang
题目: Lakshy and Orz Trees
时间复杂度: O(n*log(n))
算法: 树形DP*/
#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PI pair<int, int>
#define VI vector<int>
#define PQ priority_queue
using namespace std;
const int INF=LLONG_MAX;
const int N=5e5+10;

int n,sum,val[N];
VI e[N];

int dfs(int u,int fa,int son){
	int ans=val[u];
	PQ<int>mx;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v==fa) continue;
		mx.push(dfs(v,u,2));
	}
	for(int i=0;i<son&&!mx.empty();i++)
		ans+=mx.top(),mx.pop();
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=2;i<=n;i++){
		cin>>val[i];
		sum+=val[i];
	}
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		e[a].pb(b);
		e[b].pb(a);
	}
	cout<<sum-dfs(1,0,3)<<endl;
	return 0;
}

