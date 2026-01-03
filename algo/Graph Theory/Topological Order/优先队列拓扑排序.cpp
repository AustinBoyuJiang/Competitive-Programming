/*Author: AustinJiang
题目: 优先队列拓扑排序 
时间复杂度: O(n*log(n))
算法: 拓扑序，优先队列*/
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
const int N=510;

int n,m,lose[N];
VI won[N];
PQ<int,VI,greater<int> > q;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int p1,p2;
		cin>>p1>>p2;
		won[p1].pb(p2);
		lose[p2]++;
	}
	for(int i=1;i<=n;i++)
		if(!lose[i]) q.push(i);
	while(!q.empty()){
		int u=q.top(); q.pop();
		cout<<u<<' ';
		for(auto v:won[u]){
			lose[v]--;
			if(!lose[v]) q.push(v);
		}
	}
	return 0;
}

