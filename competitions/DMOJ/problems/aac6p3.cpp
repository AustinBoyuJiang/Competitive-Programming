#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)

namespace FastIO{
	inline int read() {int x=0; bool f=0; char ch=0; while(!isdigit(ch)) f=ch=='-',ch=getchar(); while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return f?-x:x;}
	inline int read(int &x) {return x=read();}
    template<class T> inline void write(T x) {if(x<0) x=-x,putchar('-'); if(x>9) write(x/10); putchar(x%10+'0');}
	template<class T> inline void write(T x,char ch) {write(x),putchar(ch);}
} using namespace FastIO;

const int N = 1e5+1;
const int M = N*100;

int n,mx,a[N],cnt[M*2];

signed main(){
	read(n);
	rep(i,1,n){
		read(a[i]);
		mx=max(mx,a[i]);
		a[i]+=a[i-1];
	}
	long long ans=0;
	rep(k,1,mx){
		cnt[M]++;
		rep(i,1,n){
			ans+=cnt[a[i]-k*i+M]++;
		}
		cnt[M]--;
		rep(i,1,n){
			cnt[a[i]-k*i+M]--;
		}
	}
	write(ans,'\n');
}
