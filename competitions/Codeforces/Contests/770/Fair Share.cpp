/*Author：AustinJiang
题目：
时间复杂度：O()
算法：
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
const int N=3e5+10;

int ec=1,hd[N],to[N],nx[N];
PI pos[N];
int n,tot,vis[N],cnt[N];
VI num,a[N],ans[N];
set<int> s;

void add(int u,int v,PI position){
	to[++ec]=v;
	nx[ec]=hd[u];
	hd[u]=ec;
	pos[ec]=position;
}

int find(int x){
	int l=0,r=num.size()-1;
	while(l<=r){
		int mid=l+r>>1;
		if(x<num[mid]) r=mid-1;
		else if(x>num[mid]) l=mid+1;
		else return mid+1;
	}
}

void dfs(int u){
	for(int &i=hd[u];i;i=nx[i]){
		if(vis[i>>1]) continue;
		vis[i>>1]=1;
		ans[pos[i].fir][pos[i].sec]=1;
		dfs(to[i]);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		ans[i].resize(len);
		for(int j=1;j<=len;j++){
			int x;
			cin>>x;
			a[i].pb(x);
			s.insert(x);
		}
	}
	for(auto x:s)
		num.pb(x);
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].size();j++){
			a[i][j]=find(a[i][j]);
			cnt[a[i][j]]++;
		}
	}
	for(int i=1;i<=num.size();i++){
		if(cnt[i]&1){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].size();j+=2){
			add(a[i][j],a[i][j+1],mp(i,j));
			add(a[i][j+1],a[i][j],mp(i,j+1));
		}
	}
	for(int i=1;i<=num.size();i++) dfs(i);
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++){
		for(auto x:ans[i])
			cout<<(x?'L':'R');
		cout<<endl;
	}
	return 0;
}

