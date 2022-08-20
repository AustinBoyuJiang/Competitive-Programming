/*Author: AustinJiang
��Ŀ������ 
ʱ�临�Ӷȣ�O(n*W)
�㷨��DFS����̬�滮����������
��Դ��2021 NOI Contest 
˼·��dp[i][j]��ʾ��i����Ʒ�����������Ϊj�õ�������ֵ 
cost[i][j]��ʾ��i���ﱳ���������Ϊj�õ�����ֵ����С���� */
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
const int N=1e3+10;
 
int n,m,W,ans1,ans2=INF,w[N],val[N],in[N],dp[N][N],cost[N][N];
VPI e[N];

void getMax(int &ans1,int &ans2,int val1,int val2){
	if(val1>ans1) ans1=val1,ans2=val2;
	else if(val1==ans1) ans2=min(ans2,val2);
}

void dfs(int u,int fa,int dist,int start){
	for(int i=0;start==1&&i<=W;i++){
		getMax(dp[u][i],cost[u][i],dp[fa][i],cost[fa][i]+dist*i);//��ȡ 
		if(i>=w[u]) getMax(dp[u][i],cost[u][i],dp[fa][i-w[u]]+val[u],cost[fa][i-w[u]]+dist*(i-w[u]));//ȡ 
		if(u==n) getMax(ans1,ans2,dp[u][i],cost[u][i]);
	}
	if(--in[u]>0) return;
	for(auto i:e[u])
		dfs(i.fir,u,i.sec,start);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>W;
	for(int i=1;i<=n;i++)
		cin>>w[i]>>val[i];
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].pb(mp(y,z));
		in[y]++;
	}
	memset(cost,0x3f,sizeof(cost));
	memset(cost[0],0,sizeof(cost[0]));
	memset(cost[1],0,sizeof(cost[1]));
	for(int i=n;i>=1;i--)
		if(!in[i]) dfs(i,0,0,i);
	cout<<ans1<<' '<<ans2<<endl;
	return 0;
}

