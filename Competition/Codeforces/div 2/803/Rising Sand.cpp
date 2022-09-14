/*Author：AustinJiang
题目：
时间复杂度：O()
算法：
来源：
思路：
*/
//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
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

int t,n,k,a[N],flag[N];

int check(int i){
	if(i<=1||i>=n) return 0;
	if(a[i]>a[i-1]+a[i+1]){
		if(flag[i]==0){
			flag[i]=1;
			return 1;
		}
	}
	else if(flag[i]==1){
			flag[i]=0;
			return -1;
	}
	return 0;
}

//void solve(){
//	cin>>n>>k;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//		flag[i]=0;
//	}
//	int sum=0,ans=0;
//	for(int i=0;i<=min(k-1,n);i++)
//		a[i]++;
//	for(int i=1;i<=n;i++)
//		sum+=check(i);
//	for(int l=1;l+k-1<=n;l++){
//		int r=l+k-1;
//		a[l-1]--;
//		a[r]++;
//		sum+=check(l-2);
//		sum+=check(l-1);
//		sum+=check(l);
//		sum+=check(r-1);
//		sum+=check(r);
//		sum+=check(r+1);
//		if(sum>ans) ans=sum;
//	}
//	cout<<ans<<endl;
//}



void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0;
	for(int i=2;i<n;i++){
		if(a[i]>a[i-1]+a[i+1])
			ans++;
	}
	if(k==1) cout<<(n-1)/2<<endl;
	else cout<<ans<<endl;
}

signed main(){
	cin.tie(NULL)->sync_with_stdio(false);
	cin>>t;
	while(t--)
		solve();
	return 0;
}

