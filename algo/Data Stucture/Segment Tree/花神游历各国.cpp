#include<bits/stdc++.h>
using namespace std;
const int E=400010;
int n,m,x,l,r;
long long sum[E], flag[E];
void push_up(int rt) {
	sum[rt]=sum[rt*2]+sum[rt*2+1];
	flag[rt] = flag[rt * 2] & flag[rt * 2 + 1];
}

void build(int rt,int l,int r){
	if(l==r){
		cin>>sum[rt];
		if(sum[rt] <= 1) flag [rt] = 1;
		else flag[rt] = 0;
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	push_up(rt);
}


long long get_sum(int rt,int l,int r,int x,int y){
	if(l==x&&r==y){
		return sum[rt];
	}
	int mid=(l+r)/2;
	if(y<=mid){
		return get_sum(rt*2,l,mid,x,y);
	}
	else if(x>mid){
		return get_sum(rt*2+1,mid+1,r,x,y);
	}
	else{
		return get_sum(rt*2,l,mid,x,mid)+get_sum(rt*2+1,mid+1,r,mid+1,y);
	}
}

void update(int rt, int l, int r, int x, int y) {
	if(flag[rt] == 1) return;
	if(l == r) {
		sum[rt] = sqrt(sum[rt]);
		if(sum[rt] <= 1) flag[rt] = 1;
		else flag[rt] = 0;
		return;
	}
	int mid = (l + r) / 2;
	if(y <= mid) update(rt * 2, l, mid, x, y);
	else if(x > mid) update(rt * 2 + 1, mid + 1, r, x, y);
	else update(rt *2, l, mid, x, mid), update(rt * 2 + 1, mid + 1,r, mid + 1, y);
	push_up(rt);
}

int main(){
	cin>>n;
	build(1,1,n);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>l>>r;
		if(x==1){
			cout<<get_sum(1,1,n,l,r)<<endl;
		}else {
			update(1, 1, n, l, r);
		}
	}
}
