/*Author：AustinJiang
题目：数颜色(带修莫队)
时间复杂度：O(n*sqrt(n))
算法：莫队 */
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
const int N=1e4+10;
const int A=1e6+10;

int n,m,res,tot1,tot2,block,a[N],ans[N],cnt[A];

struct QUERY{
	int id,x,y,ans;
} q[N],R[N];

bool cmp(QUERY a,QUERY b){
	if(a.x/block!=b.x/block) return a.x/block<b.x/block;
	if(a.y/block!=b.y/block) return a.y/block<b.y/block;
	return a.id<b.id;
}

void in(int x){
	if(!cnt[x]) res++;
	cnt[x]++;
}

void out(int x){
	cnt[x]--;
	if(!cnt[x]) res--;
}

void replace(int x,int l,int r){
	if(R[x].x>=l&&R[x].x<=r){
		out(a[R[x].x]);
		in(R[x].y);
	}
	swap(a[R[x].x],R[x].y);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	block=sqrt(n);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++){
		char opt;
		cin>>opt;
		if(opt=='Q'){
			cin>>q[++tot1].x;
			cin>>q[tot1].y;
			q[tot1].id=i;
		}
		else{
			cin>>R[++tot2].x;
			cin>>R[tot2].y;
			R[tot2].id=i;
		}
	}
	sort(q+1,q+tot1+1,cmp);
	int l=1,r=0,pos=0;
	for(int i=1;i<=tot1;i++){
		int x=q[i].x,y=q[i].y,id=q[i].id;
		while(l<x) out(a[l++]);
		while(l>x) in(a[--l]);
		while(r<y) in(a[++r]);
		while(r>y) out(a[r--]);
		while(R[pos+1].id<id&&pos<tot2) replace(++pos,l,r);
		while(R[pos].id>id) replace(pos--,l,r);
		ans[id]=res;
	}
	for(int i=1;i<=m;i++)
		if(ans[i]) cout<<ans[i]<<endl;
	return 0;
}

