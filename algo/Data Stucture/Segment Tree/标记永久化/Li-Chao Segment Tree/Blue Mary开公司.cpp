/*Author：AustinJiang
题目：Blue Mary开公司 
时间复杂度：O()
算法：线段树，标记永久化，李超线段树 
来源：JSOI2008 */
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
const int N=1e5+10;
const int T=5e4;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,tot,st[(T<<2)+10];

struct segement{
	double b,k;
} sg[N];

double calc(int id,int x){
	return sg[id].b+sg[id].k*(x-1);
}

int getMax(int a,int b,int x){
	if(a==0||b==0) return a+b;
	if(calc(a,x)>calc(b,x)) return a;
	else return b;
}

void update(int rt,int l,int r,int id){
	int mid=l+r>>1;
	int a=getMax(st[rt],id,mid),b=st[rt]+id-a; st[rt]=a;
	if(getMax(a,b,l)==b) update(rt<<1,l,mid,b);
	if(getMax(a,b,r)==b) update(rt<<1|1,mid+1,r,b);
}

double query(int rt,int l,int r,int x){
	if(l==r) return calc(st[rt],x);
	int mid=l+r>>1;
	if(x<=mid) return max(query(rt<<1,l,mid,x),calc(st[rt],x)); 
	else return max(query(rt<<1|1,mid+1,r,x),calc(st[rt],x));
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--){
		string opt;
		double x,y;
		cin>>opt;
		if(opt=="Query"){
			cin>>x;
			cout<<(int)query(1,1,T,x)/100<<endl;
		}
		else{
			cin>>x>>y;
			sg[++tot]={x,y};
			update(1,1,T,tot);
		}
	}
	return 0;
}

