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
const int N=3e5+10;

int n,m,k,o[N],p[N],f[N],ans[N];
VI pos[N];

struct fenwick{
	int c[N],d[N];
	
	void update(int x,int v){
		for(int i=x;i<N;i+=i&-i) c[i]+=v,d[i]+=x*v;
	}
	
	void add(int l,int r,int v){
		update(l,v);
		update(r+1,-v);
	}
	
	int query(int x) {
        int ans=0;
        for(int i=x;i;i-=i&-i) ans+=(x+1)*c[i]-d[i];
        return ans;
    }
    
    int get(int l,int r){
    	return query(r)-query(l-1);
	}
} fw;

void add(int l,int r,int v){
	if(l<=r) fw.add(l,r,v);
	else{
		fw.add(l,m,v);
		fw.add(1,r,v);
	}
}

int get(int x){
	return fw.get(x,x);
} 

struct metero {
    int l,r,a;
} met[N];

void solve(int l,int r,VI b){
	if(l==r){
		for(auto i:b)
			ans[i]=l;
		return;
	}
	int mid=l+r>>1;
	for(int i=l;i<=mid;i++)
		add(met[i].l,met[i].r,met[i].a);
	VI bl,br;
	for(auto i:b){
		__int128 cnt=0;
		for(auto x:pos[i])
			cnt+=get(x);
		if(cnt>=f[i]) bl.pb(i);
		else br.pb(i),f[i]-=cnt;
	}
	for(int i=l;i<=mid;i++)
		add(met[i].l,met[i].r,-met[i].a);
	solve(l,mid,bl);
	solve(mid+1,r,br);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>o[i];
		pos[o[i]].pb(i);
	}
	VI b;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		f[i]=p[i];
		b.pb(i);
	}
	cin>>k;
	for(int i=1;i<=k;i++)
		cin>>met[i].l>>met[i].r>>met[i].a;
	solve(1,k,b);
	for(int i=1;i<=k;i++)
		add(met[i].l,met[i].r,met[i].a);
	for(int i=1;i<=n;i++){
		__int128 cnt=0;
		for(auto x:pos[i])
			cnt+=get(x);
		if(cnt<p[i]) ans[i]=-1;
	}
	for(int i=1;i<=n;i++){
		if(ans[i]==-1) cout<<"NIE"<<endl;
		else cout<<ans[i]<<endl;
	}
	return 0;
}

