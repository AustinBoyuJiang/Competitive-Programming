/*Author：AustinJiang
题目：
时间复杂度：O()
算法：
来源：
思路：
*/
//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define random(a,b) rand()%(b-a+1)+a
#define PQ priority_queue
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f;
const int N=2e5+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int t,n,cnt1,cnt2,cnt3,a[N];
map<int,bool> vis;

void solve(){
	vis.clear();
	cnt1=cnt2=cnt3=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]=1;
		if(a[i]>0) cnt1++;
		if(a[i]<0) cnt2++;
		if(a[i]==0){
			cnt3++;
			if(cnt3>3){
				i--;
				n--;
			}
		}
	}
	if(cnt1>2||cnt2>2){
		cout<<"NO"<<endl;
		return;
	}
	for(int i=1;i+2<=n;i++){
		for(int j=i+1;j+1<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(!vis[a[i]+a[j]+a[k]]){
					cout<<"NO"<<endl;
					return;
				}
			}
		}
	}
	cout<<"YES"<<endl;
	return; 
}

signed main(){
	cin.tie(NULL)->sync_with_stdio(false);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

