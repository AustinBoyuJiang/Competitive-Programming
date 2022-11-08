/*Author：AustinJiang
题目：
时间复杂度：O()
算法：
来源：
思路：
*/
#include<bits/stdc++.h>
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
const int INF=0x3f3f3f3f;
const int N=2010;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m,ans,l[N],r[N],a[N][N],h[N][N];
stack<int> stk;

int solve(int row){
	for(int i=1;i<=m;i++){
		while(!stk.empty()&&
		h[row][i]<h[row][stk.top()]){
			r[stk.top()]=i;
			stk.pop();
		}
		stk.push(i);
	}
	while(!stk.empty()){
		r[stk.top()]=m+1;
		stk.pop();
	}
	for(int i=m;i>=1;i--){
		while(!stk.empty()&&
		h[row][i]<h[row][stk.top()]){
			l[stk.top()]=i;
			stk.pop();
		}
		stk.push(i);
	}
	while(!stk.empty()){
		l[stk.top()]=0;
		stk.pop();
	}
	int res=0;
	for(int i=1;i<=m;i++)
		res=max(res,h[row][i]*(r[i]-l[i]-1));
	return res;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]) h[i][j]=h[i-1][j]+1;
		}
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,solve(i));
	cout<<ans<<endl;
	return 0;
}

