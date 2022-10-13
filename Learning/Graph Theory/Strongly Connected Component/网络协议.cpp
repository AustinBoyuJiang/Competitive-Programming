/*Author: AustinJiang
��Ŀ: ����Э�� 
ʱ�临�Ӷ�: O(n)
�㷨: ǿ��ͨ��Tarjan�㷨
��Դ��IOI 1996 
˼·��
����a�� 
ֻ����������ͼ�������������ˣ������Ϊ0�ĵ㡣 

����b��
���㼯��ǿ��ͨ��������Ϊ1��ʱ����Ҫ����καߣ���Ϊ0
�����Ϊ0�ĵ㼯Ϊs������Ϊ0�ĵ㼯Ϊt
���1����s==1��ʱ��ֻ��Ҫ��t�����е㼯���ӵ�s���ɣ���Ϊt
���2����t>=s>1��ʱ�������ٴ����������s1,s2�������յ�t1,t2��
����s1�������ᵽt1,s2�������߶�t2����ô���ǽ�t1����s1�����������յ����һ����
�����ķ�ʽ��s-1���ߣ��õ���ͼ s'=1,t'=t-(s+1)�� 
��ʱ����ת���������1����ô����ֻ��Ҫ����t'���߼��ɡ�
���մ�Ϊ ans=(s-1)+t'=(s-1)+(t-(s+1))=s-1+t-s+1=t�� 
���3��s>=tʱ������������ǶԳƵģ���˴�Ϊs��
���ϣ�����b�Ĵ�Ϊ max(s,t)�� 
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

