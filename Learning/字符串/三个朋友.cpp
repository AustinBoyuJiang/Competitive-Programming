/*Author：AustinJiang
题目：三个朋友
时间复杂度：O(n)
算法：字符串，哈希*/
#include<bits/stdc++.h>
#define int unsigned long long
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
const int N=2e6+10;
const int base=1331;

int n,ansl,ansr,hs[N],power[N];
string str;
set<int> flag;

int get_hash(int l,int r){
	if(r<l) return 0;
	return hs[r]-hs[l-1]*power[r-l+1];
}

int join(int l,int r,int ll,int rr){
	return get_hash(l,r)*power[rr-ll+1]+get_hash(ll,rr);
}

void solve(int x){
	if(x==n/2){
		if(get_hash(0,n/2-1)!=get_hash(n/2+1,n-1)) return;
		ansl=0,ansr=n/2-1;
	}
	else if(x>n/2){
		if(get_hash(0,n/2-1)!=join(n/2,x-1,x+1,n-1)) return;
		ansl=0,ansr=n/2-1;
	}
	else{
		if(get_hash(n/2+1,n-1)!=join(0,x-1,x+1,n/2)) return;
		ansl=n/2+1,ansr=n-1;
	}
	flag.insert(get_hash(ansl,ansr));
	return;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>str;
	power[0]=1;
	for(int i=1;i<=n;i++)
		power[i]=power[i-1]*base;
	for(int i=0;i<n;i++)
		hs[i]=hs[i-1]*base+str[i]-'A';
	for(int i=0;n&1&&i<n;i++)
		solve(i);
	if(flag.empty()) cout<<"NOT POSSIBLE"<<endl;
	else if(flag.size()>1) cout<<"NOT UNIQUE"<<endl;
	else for(int i=ansl;i<=ansr;i++)
		cout<<str[i];
	return 0;
}

