/*Author：AustinJiang
题目：丘比特的烦恼 
时间复杂度：O(n^3)
算法：二分图，最优匹配，计算几何 
来源：CTSC 2000 */
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

int n,k,d,ans,x[N],y[N],e[N][N];
int cx[N],cy[N],vis[N],match[N];
map<string,int> id;

inline void lower(string &str){
	for(int i=0;i<str.size();i++)
		str[i]=tolower(str[i]);
}

inline bool check(int a,int b){
	if((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])>k*k) return 0;//两点距离是小于k 
	for(int i=1;i<=n*2;i++){
		if(i==a||i==b) continue;
		if((x[a]-x[b])*(y[i]-y[b])==(y[a]-y[b])*(x[i]-x[b]))//是否三点一线
		if((x[i]-x[a])*(x[b]-x[i])>=0&&(y[i]-y[a])*(y[b]-y[i])>=0) return 0;//是否在x区间内
	}
	return 1;
}

inline bool find(int u){
	vis[u]=1;
	for(int v=n+1;v<=n*2;v++){
		if(!e[u][v]||vis[v]) continue;
		int t=cx[u]+cy[v]-e[u][v];
		if(t==0){
			vis[v]=1;
			if(!match[v]||find(match[v])){
				match[v]=u;
				return 1;
			}
		}
		if(t>0) d=min(d,t);
	}
	return 0;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>k>>n;
	for(int i=1;i<=n*2;i++){
		string name;
		cin>>x[i]>>y[i]>>name;
		lower(name);
		id[name]=i;
	}
	for(int i=1;i<=n;i++)
		for(int j=n+1;j<=n*2;j++)
			e[i][j]=1;
	string name1,name2;
	while(cin>>name1,name1!="End"){
		cin>>name2;
		lower(name1),lower(name2);
		if(id[name1]>n) swap(name1,name2);
		cin>>e[id[name1]][id[name2]];
	}
	for(int i=1;i<=n;i++){
		for(int j=n+1;j<=n*2;j++){
			if(check(i,j)) cx[i]=max(cx[i],e[i][j]);
			else e[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		while(1){
			d=INF;
			memset(vis,0,sizeof(vis));
			if(find(i)) break;
			for(int j=1;j<=n;j++){
				if(vis[j]) cx[j]-=d;
				if(vis[j+n]) cy[j+n]+=d;
			}
		}
	}
	for(int i=n+1;i<=n*2;i++)
		ans+=e[match[i]][i];
	cout<<ans<<endl;
	return 0;
}

