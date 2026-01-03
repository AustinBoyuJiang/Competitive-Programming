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
const int N=1e6+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,t,flag[N];
VI a[N],c[N];

bool cmp(int x,int y){
	return a[x].size()>a[y].size();
}

bool including(int x,int y){
	int j=0;
	for(int i=0;i<a[y].size();i++){
		while(j<=a[x].size()&&a[x][j]<a[y][i]) j++;
		if(a[y][j]!=a[x][i]) return 0;
	}
	return 1;
}

void solve(){
	cin>>n;
	memset(flag,0,sizeof(flag));
	for(int i=1;i<=n;i++){
		a[i].clear();
		c[i].clear();
	}
	for(int i=1;i<=n;i++){
		int k,x;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x;
			a[i].pb(x);
			c[x].pb(i);
		}
		sort(a[i].begin(),a[i].end());
	}
	for(int i=1;i<=n;i++)
		sort(c[i].begin(),c[i].end(),cmp);
	for(int i=1;i<=n;i++){
		int tmp1=0,tmp2=0;
		for(int x:c[i]){
			if(flag[x]) tmp1=x;
			else{
				if(tmp2){
					if(!including(tmp2,x)){
						cout<<"YES"<<endl;
						cout<<tmp2<<' '<<x<<endl;
						return;
					}
				}
				tmp2=x;
				flag[x]=1;
			}
			if(tmp1&&tmp2){
				cout<<"YES"<<endl;
				cout<<tmp1<<' '<<tmp2<<endl;
				return;
			}
		}
	}
	cout<<"NO"<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("discuss.in","r",stdin);
//	freopen("discuss.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

