/*Author：AustinJiang
题目：Scratch Cat and Desktop Backgrounds
时间复杂度：O(n*log(n))
算法：线段树，前缀和 
来源：DMOJ MALD Contest1 */
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
const int N=1e6+10;
const int NUM=1e8;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,bl,br,a[N],sum[N];
string str;

int root,tot,lc[N],rc[N],st[N<<2];

void update(int &rt,int l,int r,int x,int y){
	if(!rt) rt=++tot;
	if(l==r){
		st[rt]+=y;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) update(lc[rt],l,mid,x,y);
	else update(rc[rt],mid+1,r,x,y);
	st[rt]=st[lc[rt]]+st[rc[rt]];
}

int query(int rt,int l,int r,int x,int y){
	if(!rt) return 0;
	if(l==x&&r==y) return st[rt];
	int mid=l+r>>1;
	if(y<=mid) return query(lc[rt],l,mid,x,y);
	else if(x>mid) return query(rc[rt],mid+1,r,x,y);
	return query(lc[rt],l,mid,x,mid)+query(rc[rt],mid+1,r,mid+1,y);
}

int solve(int x){
	tot=root=0;
	memset(lc,0,sizeof(lc));
	memset(rc,0,sizeof(rc));
	memset(st,0,sizeof(st));
	int res=0;
	for(int i=1;i<=n;i++){
		update(root,-NUM,NUM,100*sum[i-1]-x*(i-1),1);
		res+=query(root,-NUM,NUM,100*sum[i]-x*i,NUM);
	}
	return res;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>bl>>br>>str;
	n=str.size();
	for(int i=1;i<=n;i++){
		a[i]=str[i-1]-'0';
		sum[i]=sum[i-1]+(a[i]?1:-1);
	}
	cout<<solve(br)-solve(-br-1)-solve(bl-1)+solve(-bl)<<endl;
	return 0;
}

