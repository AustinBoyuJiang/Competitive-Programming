/*Author：AustinJiang
题目：Scratch Cat and Demolition
时间复杂度：O()
算法：
来源：
思路：
*/
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PQ priority_queue
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=1e6+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,k,ans,a[N],h[N],l[N],r[N];
stack<int> stk;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(h,0x3f,sizeof(h));
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x>>y;
		h[x]=min(h[x],a[x]-y);
	}
	for(int i=1;i<=n;i++){
		while(!stk.empty()&&h[i]<h[stk.top()]){
			r[stk.top()]=i;
			stk.pop();
		}
		stk.push(i);
	}
	while(!stk.empty()){
		r[stk.top()]=n+1;
		stk.pop();
	}
	for(int i=n;i>=1;i--){
		while(!stk.empty()&&h[i]<h[stk.top()]){
			l[stk.top()]=i;
			stk.pop();
		}
		stk.push(i);
	}
	while(!stk.empty()){
		l[stk.top()]=0;
		stk.pop();
	}
	for(int i=1;i<=n;i++)
		if(h[i]!=INF) ans=max(ans,h[i]*(r[i]-l[i]-1));
	cout<<ans<<endl;
	return 0;
}

