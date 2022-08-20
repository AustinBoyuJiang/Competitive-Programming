#include<bits/stdc++.h>
using namespace std;
const int E = 4e6+10;
int n,m,a,b,s[E],lx[E],rx[E],mx[E];
char k;

struct node{
	int lx, rx, mx;
};

void push_up(int rt,int l,int mid,int r){
	mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
	lx[rt] = lx[rt << 1];
	rx[rt] = rx[rt << 1 | 1];
	if(s[mid]<s[mid+1]){
		if(lx[rt << 1] == mid - l + 1) lx[rt] += lx[rt << 1 | 1];
		if(rx[rt << 1 | 1] == r - mid) rx[rt] += rx[rt << 1];
		mx[rt] = max(mx[rt], rx[rt << 1] + lx[rt << 1 | 1]);
	}
}

void build(int rt,int l,int r){
	if(l==r){
		cin>>s[l];
		lx[rt] = rx[rt] = mx[rt] = 1;
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	push_up(rt, l, mid, r);
}

node get_mx(int rt,int l,int r,int a,int b){
	node ans, ansL, ansR;
	if(l==a&&r==b){
		ans.lx = lx[rt];
		ans.rx = rx[rt];
		ans.mx = mx[rt];
		return ans;
	}
	int mid = (l + r) / 2;
	if(b <= mid) return get_mx(rt << 1, l, mid, a, b);
	else if(a > mid) return get_mx(rt << 1 | 1, mid + 1, r, a, b);
	else {
		ansL = get_mx(rt << 1, l, mid, a, mid);
		ansR = get_mx(rt << 1 | 1, mid+ 1, r, mid + 1, b);
		ans.mx = max(ansL.mx, ansR.mx);
		ans.lx = ansL.lx;
		ans.rx = ansR.rx;
		if(s[mid]<s[mid+1]){
			if(ansL.lx == mid - a + 1) ans.lx += ansR.lx;
			if(ansR.rx == b - mid) ans.rx += ansL.rx;
			ans.mx = max(ans.mx, ansL.rx + ansR.lx);
		}
		return ans;
	}
}

void update(int rt,int l,int r,int pos,int b){
	if(l==r){
		s[l]=b;
		return;
	}
	int mid=(l+r)/2;
	if(pos<=mid){
		update(rt*2,l,mid,pos,b);
	}
	else if(pos>mid){
		update(rt*2+1,mid+1,r,pos,b);
	}
	push_up(rt,l,mid,r);
}

int main(){
	cin>>n>>m;
	build(1,1,n);
	for(int i=0;i<m;i++){
		cin>>k>>a>>b;
		if(k=='Q'){
			cout<<get_mx(1,1,n,a,b).mx<<endl; 
		}
		else{
			update(1,1,n,a,b);
		}
	}
}
