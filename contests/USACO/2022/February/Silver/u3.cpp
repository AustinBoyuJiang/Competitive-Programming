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

int t,m,n,k,cnt[N];

void solve(){
	cin>>m>>n>>k;
	memset(cnt,0,sizeof(cnt));
	VI a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	int i=1;
	for(int j=1;j<=m;j++){
		while(cnt[j]){
			if(a[i]>=j&&a[i]<=j+k-1){
				cnt[a[i]]--;
				a.erase(a.begin()+i);
			}
			else i++;
			if(i==a.size()) break;
		}
		if(i==a.size()) break;
	}
	i=a.size()-1;
	for(int j=1;j<=m;j++){
		while(cnt[j]){
			if(a[i]>=j&&a[i]<=j+k-1){
				cnt[a[i]]--;
				a.erase(a.begin()+i--);
				if(i==0) break;
			}
			else{
				cout<<"NO"<<endl;
				return;
			}
		}
		if(i==0) break;
	}
	cout<<"YES"<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
		solve();
	return 0;
}

