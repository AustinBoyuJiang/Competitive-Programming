#include<bits/stdc++.h>
using namespace std;
const int E=1e5;
int n,cnt,a[E];

struct node{
	int ls,rs,value;
}st[E];
int root = 0;
void push_up(int rt){
	st[rt].ls=
}

void update(int& rt,int l,int r,int pos){
	if(rt == 0) {		//	new node
		rt = ++cnt;
		st[rt].ls = st[rt].rs = st[rt].value = 0;
	}
	
	if(l==r)
		st[rt].value += 1;
		return;
	}
	int mid=(l+r)/2;
	if(pos<=mid){
		update(st[rt].ls,l,mid,pos);
	}
	else{
		update(st[rt].rs,mid+1,r,pos);
	}
	push_up(rt);
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		update(root,1,n,a[i]); 
	}
}
