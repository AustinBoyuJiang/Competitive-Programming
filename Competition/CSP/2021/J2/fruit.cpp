/*Author：AustinJiang
题目：小熊的果篮
时间复杂度：O(n)
来源：CSP 2021 J2 */
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
const int N=2e5+10;

int n,len,a[N],L[N],R[N],ans[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	a[0]=a[n+1]=-1;
	R[0]=1,L[n+1]=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		L[i]=i-1;
		R[i]=i+1;
		if(a[i]!=a[i-1]) ans[len++]=i;
	}
	while(len){
		int cnt=0;
		for(int i=0;i<len;i++){
			cout<<ans[i];
			if(i<len-1) cout<<' ';
			int l=L[ans[i]];
			int r=R[ans[i]];
			R[l]=r;
			L[r]=l;
			if(r<=n&&a[r]==a[ans[i]]&&a[l]!=a[r]) ans[cnt++]=r;
		}
		cout<<endl;
		len=cnt;
	}
}

