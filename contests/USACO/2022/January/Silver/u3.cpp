/*Author：AustinJiang
题目：
时间复杂度：O()
算法：二分图 
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
const int N=1e5+10;

int n,m,cnt,a[N],b[N],vis[N],match[N],flag1[N],flag2[N];
queue<int> q;
VI e[N];

bool find(int u){
	if(vis[u]) return 0;
	vis[u]=1;
	q.push(u);
	for(auto v:e[u]){
		if(!match[v]){
			match[v]=u;
			return 1;
		}
		else{
			if(find(match[v])){
				match[v]=u;
				return 1;
			}
		}
	}
	return 0;
}

void dfs(int u){
	if(flag1[u]) return;
	if(match[a[u]]==u){
		cout<<u<<endl;
		flag1[u]=1;
	}
	else if(match[b[u]]==u){
		dfs(match[a[u]]);
		cout<<u<<endl;
		flag1[u]=1;
	}
	else{
		dfs(match[a[u]]);
		dfs(match[b[u]]);
		cout<<u<<endl;
		flag1[u]=1;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		e[i].pb(a[i]);
		e[i].pb(b[i]);
	}
	cnt=n;
	for(int i=1;i<=n;i++){
		if(find(i)) cnt--;
		while(!q.empty()){
			vis[q.front()]=0;
			q.pop();
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
		if(!flag1[i]) dfs(i);
	return 0;
}
