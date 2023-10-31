/*Author：AustinJiang
题目：分块1 
时间复杂度：O(n*n^0.5)
算法：分块 */
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
const int N=5e4+10;

int n,sz,bl[N],a[N],lazy[N];

void update(int l,int r,int x){
	if(bl[l]==bl[r]){
		for(int i=l;i<=r;i++)
			a[i]+=x;
		return;
	}
	for(int i=l;i<=bl[l]*sz;i++)
		a[i]+=x;
	for(int i=(bl[r]-1)*sz+1;i<=r;i++)
		a[i]+=x;
	for(int i=bl[l]+1;i<bl[r];i++)
		lazy[i]+=x; 
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	sz=sqrt(n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bl[i]=(i-1)/sz+1;
	}
	for(int i=1;i<=n;i++){
		int opt,l,r,x;
		cin>>opt>>l>>r>>x;
		if(opt==0) update(l,r,x);
		else cout<<a[r]+lazy[bl[r]]<<endl;
	}
	return 0;
}

