/*Author：AustinJiang
题目：Ant Trip
时间复杂度：O(n)
算法：图论，欧拉回路 
来源：2009 Multi-University Training Contest 12 - Host by FZU
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

int n,m,du[N],f[N],flag[N],cnt[N];

int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}

int merge(int x,int y){
	f[find(x)]=find(y);
}

signed main(){
	while(scanf("%d %d",&n,&m)!=EOF){
		memset(du,0,sizeof(du));
		memset(flag,0,sizeof(flag));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
			f[i]=i;
		for(int i=1;i<=m;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			du[a]++,du[b]++;
			merge(a,b);
		}
		for(int i=1;i<=n;i++){
			int fx=find(i);
			flag[fx]++;
			cnt[fx]+=du[i]&1;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(flag[i]<2) continue;
			if(!cnt[i]) ans++;
			else ans+=cnt[i]>>1;
		}
		printf("%d\n",ans);
	}
	return 0;
}

