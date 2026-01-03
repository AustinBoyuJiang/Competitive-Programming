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
const int N=1e5+10;

int n,m,k;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	if(k<n){
		cout<<-1<<endl;
		return 0;
	}
	if(k==n){
		for(int i=1;i<=n;i++)
			cout<<1<<' ';
		return 0;
	}
	int cnt=1;
	while(k>n-cnt+1){
		k-=n-cnt+1;
		if(++cnt>m){
			cout<<-1<<endl;
			return 0;
		}
	}
	int ans=(cnt-k%cnt)%cnt+1;
	for(int i=1;i<=n;i++){
		cout<<ans<<' ';
		ans=ans%cnt+1;
		if(!--k){
			cnt--;
			k=n-cnt+1;
			ans=(cnt-k%cnt)%cnt+1;
		}
	}
	return 0;
}

