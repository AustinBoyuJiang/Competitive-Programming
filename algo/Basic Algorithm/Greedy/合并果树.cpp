/*Author：AustinJiang
题目：
时间复杂度：O()
算法：
来源：
思路：
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
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

int n,m,tot,a[N],b[N],cnt[N],num[N];
int cl,cr,dl,dr;
ll c[N],d[N];
set<int> s;
map<int,int> id;

ll get(){
	if(cl<=cr&&dl<=dr){
		if(c[cl]<d[dl]) return c[cl++];
		else return d[dl++];
	}
	if(cl<=cr) return c[cl++];
	else return d[dl++];
}

signed main(){
	cin.tie(NULL)->sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s.insert(a[i]);
	}
	for(auto x:s){
		id[x]=++tot;
		num[tot]=x;
	}
	for(int i=1;i<=n;i++)
		b[i]=id[a[i]];
	cin>>m;
	while(m--){
		int l,r,ans=0;
		cin>>l>>r;
		if(l>r) swap(l,r);
		for(int i=l;i<=r;i++)
			cnt[b[i]]++;
		cl=1,cr=0,dl=1,dr=0;
		for(int i=1;i<=tot;i++)
			for(int j=1;j<=cnt[i];j++)
				c[++cr]=num[i];
		for(int i=l;i<=r;i++)
			cnt[b[i]]--;
		for(int i=l;i<r;i++){
			ll sum=get()+get();
			d[++dr]=sum;
			ans+=sum;
		}
		cout<<ans<<endl;
	}
	return 0;
}

