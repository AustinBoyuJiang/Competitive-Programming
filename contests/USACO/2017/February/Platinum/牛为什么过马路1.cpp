/*Author：AustinJiang
题目：牛为什么过马路1
时间复杂度：O(n*log(n))
算法：线段树 
来源：USACO2017FEB Plat
思路：求最少逆序对
f[i]表示a[i]在b[i]的位置 */
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

int n,a[N],b[N],pos[N],f[N],sum[N<<2];

void update(int rt,int l,int r,int x){
	if(l==r){
		sum[rt]=1;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) update(rt*2,l,mid,x);
	else update(rt*2+1,mid+1,r,x);
	sum[rt]=sum[rt*2]+sum[rt*2+1];
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return sum[rt];
	int mid=l+r>>1;
	if(y<=mid) return query(rt*2,l,mid,x,y);
	else if(x>mid) return query(rt*2+1,mid+1,r,x,y);
	else return query(rt*2,l,mid,x,mid)+query(rt*2+1,mid+1,r,mid+1,y);
}

int solve(int a[],int b[]){
	memset(sum,0,sizeof(sum));
	int cnt=0;
	for(int i=1;i<=n;i++){
		pos[b[i]]=i;
	}
	for(int i=1;i<=n;i++){
		f[i]=pos[a[i]];
		update(1,1,n,f[i]);
		if(f[i]<n) cnt+=query(1,1,n,f[i]+1,n);
	}
	int ans=cnt;
	for(int i=1;i<=n;i++){
		cnt+=(n-f[i])-(f[i]-1);
		ans=min(ans,cnt);
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	cout<<min(solve(a,b),solve(b,a))<<endl;
	return 0;
}

