/*Author：AustinJiang
题目：Fixed Point Guessing
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
const int N=1e4+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int t,n,a[N];

void dfs(int l,int r){
	if(l==r){
		cout<<"! "<<l<<endl;
		cout.flush();
		return;
	}
	int mid=l+r>>1;
	cout<<"? "<<l<<" "<<mid<<endl;
	cout.flush();
	int cnt=0;
	for(int i=l;i<=mid;i++){
		cin>>a[i];
		if(a[i]<l||a[i]>mid) cnt++;
	}
	if(cnt%2!=(mid-l+1)%2) dfs(l,mid);
	else dfs(mid+1,r);
}

void solve(){
	cin>>n;
	dfs(1,n);
}

signed main(){
	cin.tie(NULL)->sync_with_stdio(false);
	cin>>t;
	while(t--)
		solve();
	return 0;
}

