/*Author：AustinJiang
题目：Animal Farm
时间复杂度：O(n^2)
算法：MIT，最小生成树 
来源：CCC '10 S4 */
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
const int N=1000;
const int M=200;
const int E=10;

int n,m,t,cnt,ans1,ans2=INF,ep,ei[E],co[N],f[M];

struct edge{
	int u,v,w;
} e[N],ee[N],Map[N][N];

bool cmp(edge a,edge b){
	return a.w<b.w;
}

int find1(int x){
	return f[x]==x?x:f[x]=find1(f[x]);
}

int find2(int x){
	return co[x]==x?x:co[x]=find2(co[x]);
}

int MIT(){
	int ans=0;
	for(int i=1;i<=m;i++)
		f[i]=i;
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int fx=find1(e[i].u);
		int fy=find1(e[i].v);
		if(fx==fy) continue;
		f[fx]=fy;
		ans+=e[i].w;
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m;
	for(int i=1;i<N;i++)
		co[i]=i;
	for(int i=1;i<=m;i++){
		cin>>ep;
		for(int j=0;j<ep;j++){
			cin>>ei[j];
			n=max(n,ei[j]);
		}
		for(int j=0;j<ep;j++){
			int u=min(ei[j],ei[(j+1)%ep]);
			int v=max(ei[j],ei[(j+1)%ep]);
			co[find2(u)]=find2(v);
			cin>>Map[u][v].w;
			if(!Map[u][v].u) Map[u][v].u=i;
			else Map[u][v].v=i;
		}
	}
	for(int i=1;i<n;i++)
		if(find2(i)!=find2(i+1)) {t=1; break;}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(Map[i][j].u||Map[i][j].v) e[++cnt]=Map[i][j];
	ans1=MIT();
	if(t){
		cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(Map[i][j].u&&Map[i][j].v) e[++cnt]=Map[i][j];
		ans2=MIT();
	}
	cout<<min(ans1,ans2)<<endl;
	return 0;
}

