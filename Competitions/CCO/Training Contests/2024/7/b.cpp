/*
 * Author: Austin Jiang
 * Date: 5/10/2024 7:44:28 PM
 * Problem:
 * Source:
 * Description:
*/

/* Configuration */
//#define MULTICASES
//#define LOCAL
//#define READLOCAL
//#define FILESCOMP
//#define SETMEM
#define FASTIO
//#define NDEBUG
#define OPTIMIZE
//#define INTTOLL

#ifdef OPTIMIZE
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#endif

#include<bits/stdc++.h>
using namespace std;

#ifdef INTTOLL
#define int long long
#endif

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'

/* Pair */
#define fir first
#define sec second

/* STL */
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define eb emplace_back
#define ef emplace_front
#define pb push_back
#define pf push_front
#define all(v) v.begin(), v.end()

/* Data type */
using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
template <class T> using Vec = vector<T>;

void SETUP(){
	#ifdef FASTIO
	cin.tie(nullptr)->sync_with_stdio(false);
	#endif
	#ifdef READLOCAL
	freopen("in.txt","r",stdin);
	freopen("stdout.txt","w",stdout);
	#endif
}

/* ========================================| Main Program |======================================== */

int n,q;
VI a;

struct segtree{
	int root=0,tot=0;
	VI lc,rc;
	Vec<VI> lazy;
	Vec<multiset<int>> st;
	
	segtree(int n){
		int sz=n*2+1;
		lc.resize(sz);
		rc.resize(sz);
		lazy.resize(sz);
		st.resize(sz);
	}
	
	int check(int &rt,int l,int r,int k){
		if(!rt){
			rt=++tot;
			rep(i,l,r) st[rt].insert(a[i]);
		}
		int mx=*st[rt].rbegin();
		if(mx<=k) return k;
		st[rt].erase(--st[rt].end());
		st[rt].insert(k);
		lazy[rt].pb(k);
		return mx;
	}
	
	void push_down(int rt,int l,int mid,int r){
		for(int k:lazy[rt]){
			k=check(lc[rt],l,mid,k);
			check(rc[rt],mid+1,r,k);
		} lazy[rt].clear();
	}
	
	int update(int &rt,int l,int r,int x,int y,int k){
		if(!rt){
			rt=++tot;
			rep(i,l,r) st[rt].insert(a[i]);
		}
		if(l==x&&r==y) return check(rt,l,r,k);
		int mid=(l+r)>>1,res=-1;
		push_down(rt,l,mid,r);
		if(y<=mid) res=update(lc[rt],l,mid,x,y,k);
		else if(x>mid) res=update(rc[rt],mid+1,r,x,y,k);
		else{
			res=update(lc[rt],l,mid,x,mid,k);
			res=update(rc[rt],mid+1,r,mid+1,y,res);
		}
		if(k!=res){
			st[rt].insert(k);
			st[rt].erase(st[rt].find(res));
		}
		return res;
	}
	
	int upd(int l,int r,int x){
		return update(root,1,n,l,r,x);
	}
};

inline void SOLVE(int Case){
	cin>>n>>q;
	a.resize(n+1);
	rep(i,1,n){
		cin>>a[i];
	}
	segtree st(n);
	while(q--){
		int l,r,x;
		cin>>l>>r>>x;
		if(l<=r){
			x=st.upd(l,r,x);
		}
		else{
			x=st.upd(l,n,x);
			x=st.upd(1,r,x);
		}
		cout<<x<<endl;
	}
}

/* =====================================| End of Main Program |===================================== */

signed main(){
	#ifdef SETMEM
    int size(512<<20);  //512MB
    __asm__("movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	#endif
	#ifndef FILESCOMP
	SETUP();
	int CASE=1;
	#ifdef MULTICASES
	cin>>CASE;
	#endif
	rep(i,1,CASE){
		#ifdef LOCAL
		printf("Case #%d: \n",i);
		#endif
		SOLVE(i);
	}
	#else
	system("fc stdout.txt out.txt");
	#endif
	#ifdef SETMEM
    exit(0);
    #endif
	return 0;
}

/* stuff you should look for
	* read questions at least 3 times!!!
    * think more and then code!!!
    * partial points are GOD.
	* remember to initialize variables
    * don't stuck on one question for two long (like 30-45 min)
    * Debug: (a) read your code once, check overflow and edge case
    * Debug: (b) create your own test case
    * Debug: (c) adversarial testing
*/

