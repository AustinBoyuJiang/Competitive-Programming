#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'

const int N = 1e6+10;

int n,sum,ans=1,a[N],b[N],f[N],s[N*3],cnt[N],siz[N];

int gcd(int a,int b){return b?gcd(b,a%b):a;}

int root(int x){
	if(f[x]==x) return x;
	return f[x]=root(f[x]);
}

void merge(int u,int v){
	if(root(u)==root(v)) return;
	f[root(u)]=root(v);
}

void check(){
	rep(i,1,n*2){
		f[i]=i;
		cnt[i]=0;
		siz[i]=0;
	}
	if(s[(n-1)*3+1]){
		merge(1,n+1);
	}
	for(int i=2;i<=n;i++){
		if(s[(i-2)*3+1]){
			merge(i,i-1);
		}
		if(s[(i-2)*3+2]){
			merge(i+n,i-1+n);
		}
		if(s[(i-2)*3+3]){
			merge(i,i+n);
		}
	}
	rep(i,1,n*2){
		if(i<=n){
			cnt[root(i)]+=a[i];
		}
		else{
			cnt[root(i)]+=b[i-n];
		}
		siz[root(i)]++;
	}
	set<pair<int,int>> s;
	int res=0;
	rep(i,1,n*2){
		if(f[i]==i){
			res++;
			int g=gcd(cnt[i],siz[i]);
			cnt[i]/=g;
			siz[i]/=g;
			s.insert({cnt[i],siz[i]});
		}
		if(s.size()>1){
			return;
		}
	}
//	cout<<"here"<<endl;
	ans=max(ans,res);
//	if(res==6){
//		cout<<">>>>>>>>"<<endl;
//		rep(i,1,n*2){
//			cout<<root(i)<<endl;
//			if(i==)
//		}
//	}
}

void dfs(int u){
	if(u==(n-1)*3+2){
		check();
		return;
	}
	s[u]=0;
	dfs(u+1);
	s[u]=1;
	dfs(u+1);
}

signed main(){
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
	}
	rep(i,1,n){
		cin>>b[i];
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

