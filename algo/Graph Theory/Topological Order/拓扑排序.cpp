/*Author: AustinJiang
题目: 拓扑排序 
时间复杂度: O(n+m)
算法: 拓扑序*/
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
const int N=110;

int n,m,ans,cnt[N],vis[N];
VI Map[N];
queue<int> q;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		Map[a].pb(b);
		cnt[b]++;
	}
	for(int i=1;i<=n;i++)
		if(!cnt[i]) q.push(i);
	while(!q.empty()){
		ans++;
		int u=q.front(); q.pop();
		for(auto i:Map[u])
			if(!--cnt[i]) q.push(i);
	}
	if(ans==n) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}

