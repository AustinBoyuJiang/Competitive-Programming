/*Author：AustinJiang
题目：
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
const int INF=0x3f3f3f3f;
const int N=1e5+10;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,q,a[N],sum[N<<2],sum2[N<<2];

void update(int rt,int l,int r,int x,int y,int v){
	sum[rt]+=v*(y-x+1);
	if(l==x&&r==y){
		sum2[rt]+=v;
		return;
	}
	int mid=l+r>>1;
	if(y<=mid) update(rt<<1,l,mid,x,y,v);
	else if(x>mid) update(rt<<1|1,mid+1,r,x,y,v);
	else update(rt<<1,l,mid,x,mid,v),update(rt<<1|1,mid+1,r,mid+1,y,v);
}

int query(int rt,int l,int r,int x,int y){
	if(l==x&&r==y) return sum[rt];
	int mid=l+r>>1;
	if(y<=mid) return query(rt<<1,l,mid,x,y)+sum2[rt]*(y-x+1);
	else if(x>mid) return query(rt<<1|1,mid+1,r,x,y)+sum2[rt]*(y-x+1);
	else return query(rt<<1,l,mid,x,mid)+query(rt<<1|1,mid+1,r,mid+1,y)+sum2[rt]*(y-x+1);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		update(1,1,n,i,i,x);
	}
	for(int i=1;i<=q;i++){
		char opt;
		int a,b,c;
		cin>>opt;
		if(opt=='C'){
			cin>>a>>b>>c;
			update(1,1,n,a,b,c);
		}
		else{
			cin>>a>>b;
			cout<<query(1,1,n,a,b)<<endl;
		}
	}
	return 0;
}

