/*Author: AustinJiang
题目: 网络协议 
时间复杂度: O(n)
算法: 强连通，Tarjan算法
来源：IOI 1996 
思路：
任务a： 
只需把软件给到图中所有起点就行了，即入度为0的点。 

任务b：
当点集（强连通分量）数为1的时候不需要添加任何边，答案为0
设入度为0的点集为s，出度为0的点集为t
情况1：当s==1的时候只需要让t中所有点集链接到s即可，答案为t
情况2：当t>=s>1的时候则至少存在两个起点s1,s2和两个终点t1,t2。
假设s1至少能揍到t1,s2至少能走动t2，那么我们将t1连到s1，这样起点和终点各少一个。
这样的方式连s-1条边，得到新图 s'=1,t'=t-(s+1)。 
此时问题转换成了情况1，那么我们只需要再连t'条边即可。
最终答案为 ans=(s-1)+t'=(s-1)+(t-(s+1))=s-1+t-s+1=t。 
情况3：s>=t时，这种情况答案是对称的，因此答案为s。
综上，任务b的答案为 max(s,t)。 
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
const int N=200;

int n,s,t,tot,cnt,dfn[N],low[N],flag[N],pos[N],in[N],out[N];
stack<int> stk;
VI e[N];

void dfs(int u){
	dfn[u]=low[u]=++tot;
	flag[u]=1,stk.push(u);
	for(auto v:e[u]){
		if(!dfn[v]) dfs(v);
		if(flag[v]) low[u]=min(low[u],low[v]);
	}
	if(dfn[u]!=low[u]) return;
	pos[u]=++cnt;
	while(stk.top()!=u){
		pos[stk.top()]=cnt;
		flag[stk.top()]=0,stk.pop();
	}
	flag[u]=0,stk.pop();
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1,j;i<=n;i++)
		while(cin>>j,j)
			e[i].pb(j);
	for(int i=1;i<=n;i++)
		if(!dfn[i]) dfs(i);
	for(int i=1;i<=n;i++)
		for(auto j:e[i]){
			if(pos[i]==pos[j]) continue;
			if(Map[pos[i]][pos[j]]) continue;
			out[pos[i]]++,in[pos[j]]++;
			Map[pos[i]][pos[j]]=1;
		}
	for(int i=1;i<=cnt;i++){
		if(!in[i]) s++;
		if(!out[i]) t++;
		
	}
	cout<<s<<endl;
	if(cnt==1) cout<<0<<endl;
	else cout<<max(s,t)<<endl;
	return 0;
}

