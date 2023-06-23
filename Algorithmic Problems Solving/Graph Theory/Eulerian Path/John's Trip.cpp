/*Author：AustinJiang
题目：John's Trip
时间复杂度：O(t*m*log(m))
算法：欧拉回路 
来源：CERC 1995
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
const int N=100;
const int M=4e3;

int x,y,z,flag,tot,cnt,head[N],du[N],vis[M],ans[M];

struct edge{
	int to,id,nxt;
} e[M];

struct side{
	int x,y,z;
};

vector<side> ee;

bool cmp(side a,side b){
	return a.z>b.z;
}

void add(int x,int y,int z){
	e[++tot].nxt=head[x];
	e[tot].to=y;
	e[tot].id=z;
	head[x]=tot;
}

void dfs(int u,int id){
	for(int &i=head[u];i;i=e[i].nxt){
		if(vis[e[i].id]) continue;
		vis[e[i].id]=1;
		dfs(e[i].to,e[i].id);
	}
	if(id) ans[++cnt]=id;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>x>>y,x){
		memset(head,0,sizeof(head));
		memset(vis,0,sizeof(vis));
		memset(du,0,sizeof(du));
		ee.clear();
		flag=tot=cnt=0;
		cin>>z;
		ee.pb((side){x,y,z});
		ee.pb((side){y,x,z});
		int n=max(x,y);
		int s=min(x,y);
		du[x]++,du[y]++;
		while(cin>>x>>y,x){	
			cin>>z;
			ee.pb((side){x,y,z});
			ee.pb((side){y,x,z});
			n=max(x,y);
			du[x]++,du[y]++;
		}
		for(int i=1;i<=n;i++)
			if(du[i]&1){
				flag=1;
				break;
			}
		if(flag){
			cout<<"Round trip does not exist."<<endl;
			continue;
		}
		sort(ee.begin(),ee.end(),cmp);
		for(auto i:ee)
			add(i.x,i.y,i.z);
		dfs(s,0);
		for(int i=cnt;i>1;i--)
			cout<<ans[i]<<' ';
		cout<<ans[1]<<endl;
	}
	return 0;
}

