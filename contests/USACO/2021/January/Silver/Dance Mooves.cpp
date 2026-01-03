/*Author：AustinJiang
题目：Dance Moove
时间复杂度：O(n+k)
算法：DFS
来源：USACO 2021 January Silver*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
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
const int N=2e5+10;

int n,k,tot,ans[N],a[N],b[N],from[N],p[N],vis[N],cnt[N];
queue<int> q;
VI s[N];

void remove(int u){
	for(auto x:s[u]){
		cnt[x]--;
		if(!cnt[x]) tot--;
	}
}

void add(int u){
	for(auto x:s[u]){
		if(!cnt[x]) tot++;
		cnt[x]++;
	}
}

void dfs(int u){
	vis[u]=1;
	add(u);
	q.push(u);
	if(!vis[p[u]])
		dfs(p[u]);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++){
		from[i]=i;
		s[i].pb(i);
	}
	for(int i=1;i<=k;i++){
		s[from[a[i]]].pb(b[i]);
		s[from[b[i]]].pb(a[i]);
		swap(from[a[i]],from[b[i]]);
	}
	for(int i=1;i<=n;i++)
		p[from[i]]=i;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
			int tmp=tot;
			while(!q.empty()){
				ans[q.front()]=tmp;
				remove(q.front());
				q.pop();
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
	return 0;
}

