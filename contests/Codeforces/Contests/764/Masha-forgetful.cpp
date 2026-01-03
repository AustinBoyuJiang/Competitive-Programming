/*Author：AustinJiang
题目：Masha-forgetful
时间复杂度：O(t*n*log(n))
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
const int N=1e5+10;

int t,n,m,cnt,dp[N];
string p,ans[N];
struct str{int l,r,id;};
map<string,str> Map;

bool ok(int l,int r){
	if(l>=1&&r<=m&&Map.count(p.substr(l-1,r-l+1))) return 1;
	else return 0;
}

void get_ans(int pos){
	if(pos==dp[pos]) return;
	get_ans(dp[pos]);
	ans[++cnt]=p.substr(dp[pos],pos-dp[pos]);
}

void solve(){
	cin>>n>>m;
	Map.clear();
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		for(int j=1;j<=m;j++){
			if(j+1<=m) Map[s.substr(j-1, 2)]={j,j+1,i};
			if(j+2<=m) Map[s.substr(j-1, 3)]={j,j+2,i};
		}
	}
	cin>>p;
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=m;i++){
		for(int j=2;j<=3;j++){
			if(ok(i-j+1,i)&&dp[i-j]!=-1){
				dp[i]=i-j;
				break;
			}
		}
	}
	if(dp[m]==-1) cout<<-1<<endl;
	else{
		cnt=0;
		get_ans(m);
		cout<<cnt<<endl;
		for(int i=1;i<=cnt;i++)
			cout<<Map[ans[i]].l<<" "<<Map[ans[i]].r<<" "<<Map[ans[i]].id<<endl;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
		solve();
	return 0;
}

