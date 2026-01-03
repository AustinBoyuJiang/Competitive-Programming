/*Author：AustinJiang
题目：网络分析 
时间复杂度：O(n+m)
算法：并查集 */
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
const int N=1e5+1e4+10;

int n,m,tot,val[N],f[N];

int find(int x){
	if(x==f[x]) return x;
	if(f[x]==f[f[x]]) return f[x];
	int fx=find(f[x]);
	val[x]+=val[f[x]];
	return f[x]=fx;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		f[++tot]=i;
	for(int i=1;i<=m;i++){
		int opt,a,b;
		cin>>opt>>a>>b;
		if(opt==1&&find(a)!=find(b)) f[find(a)]=f[find(b)]=f[++tot]=tot;
		if(opt==2) val[find(a)]+=b;
	}
	for(int i=1;i<=n;i++){
		if(i==find(i)) cout<<val[i]<<' ';
		else cout<<val[i]+val[f[i]]<<' ';
	}
	return 0;
}

