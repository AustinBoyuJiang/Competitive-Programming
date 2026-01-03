/*Author：AustinJiang
题目：Do You Know Your ABCs?
时间复杂度：O()
算法：
来源：
思路：
*/
#pragma GCC optimize(2)
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

int t,n,a[10],f[10],vis[10],tmp[10];

struct answer{
	int a,b,c;
	
	bool operator<(const answer b) const{
		if(this->a!=b.a) return this->a<b.a;
		if(this->b!=b.b) return this->b<b.b;
		return this->c<b.c;
    }
};

set<answer> ans;

inline bool check(){
	if(!f[1]){
		if(f[2]&&f[4]) f[1]=f[4]-f[2];
		if(f[2]&&f[6]) f[1]=f[6]-f[3];
		if(f[5]&&f[7]) f[1]=f[7]-f[5];
		if(f[2]&&f[3]&&f[7]) f[1]=f[7]-f[2]-f[3];
	}
	if(!f[2]){
		if(f[1]&&f[4]) f[2]=f[4]-f[1];
		if(f[3]&&f[5]) f[2]=f[5]-f[3];
		if(f[6]&&f[7]) f[2]=f[7]-f[6];
		if(f[1]&&f[3]&&f[7]) f[2]=f[7]-f[1]-f[3];
	}
	if(!f[3]){
		if(f[1]&&f[6]) f[3]=f[6]-f[1];
		if(f[2]&&f[5]) f[3]=f[5]-f[2];
		if(f[4]&&f[7]) f[3]=f[7]-f[4];
		if(f[1]&&f[2]&&f[7]) f[3]=f[7]-f[1]-f[2];
	}
	if(!f[4]) f[4]=f[1]+f[2];
	if(!f[5]) f[5]=f[2]+f[3];
	if(!f[6]) f[6]=f[1]+f[3];
	if(!f[7]) f[7]=f[1]+f[2]+f[3];
	if(f[4]!=f[1]+f[2]) return 0;
	if(f[5]!=f[2]+f[3]) return 0;
	if(f[6]!=f[1]+f[3]) return 0; 
	if(f[7]!=f[1]+f[2]+f[3]) return 0;
	if(f[1]<1||f[2]<1||f[3]<1) return 0;
	return 1;
}

inline void dfs(int pos){
	if(pos>7){
		for(int i=1;i<=7;i++)
			tmp[i]=f[i];
		if(check()){
			sort(f+1,f+4);
			ans.insert({f[1],f[2],f[3]});
		}
		for(int i=1;i<=7;i++)
			f[i]=tmp[i];
		return;
	}
	for(int i=1;i<=7;i++){
		if(vis[i]) continue;
		vis[i]=1;
		f[pos]=a[i];
		dfs(pos+1);
		vis[i]=0;
	}
}

inline void solve(){
	cin>>n;
	memset(a,0,sizeof(a));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ans.clear();
	dfs(1);
	cout<<ans.size()<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
		solve();
	return 0;
}

