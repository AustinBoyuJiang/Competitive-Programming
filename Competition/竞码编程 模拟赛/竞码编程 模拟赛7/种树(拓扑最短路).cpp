/*Author：AustinJiang
题目：
时间复杂度：O()
算法：
来源：
思路：
*/
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
const int N=3e5+10;

int n,ans,val[N],dist[N],cnt[N];
VI e[N];

void add(int u,int v){
	e[u].pb(v);
}

void clear(int u){
	e[u].clear();
}

void init(int st,int ed){
	clear(0);
	clear(n*3);
	clear(n*3-1);
	clear(n*3-2);
	add(0,st);
	add((n-1)*3+ed,n*3+1);
}

int dijk(int st,int ed){
	init(st,ed);
	memset(dist,-0x3f,sizeof(dist));
	memset(cnt,0,sizeof(cnt));
	for(int u=0;u<=3*n;u++)
		for(auto v:e[u])
			cnt[v]++;
	for(int u=0;u<=3*n+1;u++)
		if(!cnt[u]&&u!=0)
			for(auto v:e[u])
				cnt[v]--;
	queue<int> q;
	dist[0]=0;
	q.push(0);
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(auto v:e[u]){
			dist[v]=max(dist[v],dist[u]+val[v]);
			if(!--cnt[v]) q.push(v);
		}
	}																																					
	return dist[n*3+1];
}

int solve1(){
	for(int i=0;i<=n*3;i++)
		clear(i);
	for(int i=1;i<n;i++){
		if(i&1){
			add((i-1)*3+1,i*3+2);
			add((i-1)*3+1,i*3+3);
			add((i-1)*3+2,i*3+3);
		}
		else{
			add((i-1)*3+2,i*3+1);
			add((i-1)*3+3,i*3+1);
			add((i-1)*3+3,i*3+2);
		}
	}
	return max(max(dijk(1,2),dijk(1,3)),dijk(2,3));
}

int solve2(){
	for(int i=0;i<=n*3;i++)
		clear(i);
	for(int i=1;i<n;i++){
		if(i&1){
			add((i-1)*3+2,i*3+1);
			add((i-1)*3+3,i*3+1);
			add((i-1)*3+3,i*3+2);
		}
		else{
			add((i-1)*3+1,i*3+2);
			add((i-1)*3+1,i*3+3);
			add((i-1)*3+2,i*3+3);
		}
	}
	return max(dijk(2,1),max(dijk(3,1),dijk(3,2)));
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n*3;i++)
		cin>>val[i];
	cout<<max(solve1(),solve2())<<endl;
	return 0;
}

