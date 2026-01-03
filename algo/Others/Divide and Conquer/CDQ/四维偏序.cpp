/*Author：AustinJiang
题目：四维偏序 
时间复杂度：O(n*log(n)^3)
算法：CDQ分治，线段树 */
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
const int N=3e4+10;

int n,tot,ans,sum[N<<2];

struct thing{
	int a,b,c,d,cnt,flag,low;
} t[N],p[N],tmp[N];

bool cmp(thing a,thing b){
	if(a.a!=b.a) return a.a<b.a;
	if(a.b!=b.b) return a.b<b.b;
	if(a.c!=b.c) return a.c<b.c;
	return a.d<b.d;
}

bool check(thing a,thing b){
	if(a.a!=b.a) return 0;
	if(a.b!=b.b) return 0;
	if(a.c!=b.c) return 0;
	return a.d==b.d;
}

void update(int rt,int l,int r,int x,int v){
	if(l==r){
		sum[rt]+=v;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) update(rt<<1,l,mid,x,v);
	else update(rt<<1|1,mid+1,r,x,v);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return sum[rt];
	int mid=l+r>>1;
	if(y<=mid) return query(rt<<1,l,mid,x,y);
	else if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
	return query(rt<<1,l,mid,x,mid)+query(rt<<1|1,mid+1,r,mid+1,y);
}

void solve2(int l,int r){
	if(r<=l) return;
	int mid=l+r>>1;
	solve2(l,mid);
	solve2(mid+1,r);
	int i=l,k=l;
	for(int j=mid+1;j<=r;j++){
		while(i<=mid&&p[i].c<=p[j].c){
			if(!p[i].flag) update(1,1,N,p[i].d,p[i].cnt);
			tmp[k++]=p[i++];
		}
		if(p[j].flag) p[j].low+=query(1,1,N,1,p[j].d);
		tmp[k++]=p[j];
	}
	while(i<=mid){
		if(!p[i].flag) update(1,1,N,p[i].d,p[i].cnt);
		tmp[k++]=p[i++];
	}
	for(int i=l;i<=mid;i++)
		if(!p[i].flag) update(1,1,N,p[i].d,-p[i].cnt);
	for(int i=l;i<=r;i++) p[i]=tmp[i];
}

void solve1(int l,int r){
	if(r<=l) return;
	int mid=l+r>>1;
	solve1(l,mid);
	solve1(mid+1,r);
	for(int i=l;i<=mid;i++) p[i].flag=0;
	for(int i=mid+1;i<=r;i++) p[i].flag=1;
	int j=mid+1,k=l;
	for(int i=l;i<=mid;i++){
		while(j<=r&&p[j].b<p[i].b) tmp[k++]=p[j++];
		tmp[k++]=p[i];
	}
	while(j<=r) tmp[k++]=p[j++];
	for(int i=l;i<=r;i++) p[i]=tmp[i];
	solve2(l,r);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>t[i].a>>t[i].b>>t[i].c>>t[i].d;
	sort(t+1,t+n+1,cmp);
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<n&&check(t[i],t[j+1])) j++;
		p[++tot]=t[i];
		p[tot].cnt=j-i+1;
		i=j;
	}
	solve1(1,tot);
	for(int i=1;i<=tot;i++)
		ans+=(p[i].low+p[i].cnt-1)*p[i].cnt;
	cout<<ans<<endl;
	return 0;
}

