/*Author: AustinJiang
��Ŀ: ԭʼ����
ʱ�临�Ӷ�: O(n)
�㷨: ͼ�ۣ�ŷ����·
˼·: ����ÿ�������Ⱥͳ���һ������֤����һ�ʻ��꣬����������ŷ����·����Ҫ��1����Ϊ������������*/
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
const int N=1e3+10;

int m,n,ans,in[N],out[N],flag[N],vis[N];
VI e[N];

int dfs(int x){
	int res=in[x]==out[x];
	for(auto v:e[x]){
		if(vis[v]) continue;
		vis[v]=1;
		res&=dfs(v);
	}
	return res;
}

signed main(){
	cin>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
		in[v]++;out[u]++;
		flag[u]=flag[v]=1;
		n=max(n,max(u,v));
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]&&flag[i]) ans+=dfs(i);
	for(int i=1;i<=n;i++)
		if(flag[i]) ans+=max(in[i],out[i]);
	cout<<ans<<endl;
	return 0;
}
