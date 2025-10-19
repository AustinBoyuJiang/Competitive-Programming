/*Author：AustinJiang
题目：Searching for Soulmates
时间复杂度：O(log(a)^2)
算法：贪心 */
#include<bits/stdc++.h>
#define int long long
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

int n,a,b;

int muti(int a,int b){
	if(a>b) return INF;
	int power=0,cnt=0;
	while(a*2<=b){
		a*=2;
		cnt++;
		power++;
	}
	int tmp=b-a;
	for(int i=power;i>=0;i--){
		int x=pow(2,i);
		cnt+=tmp/x;
		tmp%=x;
	}
	return cnt;
}

void solve(){
	cin>>a>>b;
	int cnt=0,ans=muti(a,b);
	while(a>1){
		if(a&1) a++,cnt++;
		a/=2,cnt++;
		if(a<=b) ans=min(ans,cnt+muti(a,b));
	}
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--){
		solve();
	}
	return 0;
}

