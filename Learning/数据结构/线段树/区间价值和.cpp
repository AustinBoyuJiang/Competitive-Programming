/*Author：AustinJiang
题目：区间价值和
时间复杂度：O(n*log(n))
算法：线段树 
来源：CF */
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
const int N=5e5+10;
const int A=1e9;
const int MOD=1e9+7;

int n,ans,root,tot,a[N],lv[N],rv[N],lc[N<<2],rc[N<<2],sum[N<<2];

void push_up(int rt){
	sum[rt]=(sum[lc[rt]]+sum[rc[rt]])%MOD;
}

void update(int &rt,int l,int r,int pos,int x){
	if(!rt) rt=++tot;
	if(l==r){
		sum[rt]+=x;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid) update(lc[rt],l,mid,pos,x);
	else update(rc[rt],mid+1,r,pos,x);
	push_up(rt);
}

int query(int rt,int l,int r,int x,int y){
	if(!rt) return 0;
	if(l==x&&r==y) return sum[rt];
	int mid=l+r>>1;
	if(y<=mid) return query(lc[rt],l,mid,x,y);
	else if(x>mid) return query(rc[rt],mid+1,r,x,y);
	else return (query(lc[rt],l,mid,x,mid)+query(rc[rt],mid+1,r,mid+1,y))%MOD;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		update(root,0,A,a[i],i);
		lv[i]=query(root,0,A,0,a[i]);
	}
	root=tot=0;
	memset(lc,0,sizeof(lc));
	memset(rc,0,sizeof(rc));
	memset(sum,0,sizeof(sum));
	for(int i=n;i>=1;i--){
		rv[i]=query(root,0,A,0,a[i]);
		update(root,0,A,a[i],n-i+1);
	}
	for(int i=1;i<=n;i++){
		ans+=a[i]*(lv[i]*(n-i+1)+rv[i]*i);
		ans%=MOD;
	}
	cout<<ans<<endl; 
	return 0;
}

