#include<bits/stdc++.h>
using namespace std;
const int E=4e6+10;
int n,m,x,y,lazy[E];
string str;

struct node{
	int s4,s7,s47,s74;
}cnt[E];

void push_up(int rt){
	cnt[rt].s4=cnt[rt*2].s4+cnt[rt*2+1].s4;
	cnt[rt].s7=cnt[rt*2].s7+cnt[rt*2+1].s7;
	cnt[rt].s47=max(cnt[rt*2].s4+cnt[rt*2+1].s47,cnt[rt*2].s47+cnt[rt*2+1].s7);
	cnt[rt].s74=max(cnt[rt*2].s7+cnt[rt*2+1].s74,cnt[rt*2].s74+cnt[rt*2+1].s4);
}

void push_down(int rt){
	if(lazy[rt]){
		swap(cnt[rt*2].s4,cnt[rt*2].s7);
		swap(cnt[rt*2].s47,cnt[rt*2].s74);
		swap(cnt[rt*2+1].s4,cnt[rt*2+1].s7);
		swap(cnt[rt*2+1].s47,cnt[rt*2+1].s74);
		lazy[rt*2]^=lazy[rt];
		lazy[rt*2+1]^=lazy[rt];
		lazy[rt]=0;
	}
}

void build(int rt,int l,int r){
	if(l==r){
		if(str[l-1]=='4'){
			cnt[rt].s4=1;
		}
		else{
			cnt[rt].s7=1;
		}
		cnt[rt].s47=1;
		cnt[rt].s74=1;
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	push_up(rt);
}

void update(int rt,int l,int r,int x,int y){
	if(l==x&&r==y){
		swap(cnt[rt].s4,cnt[rt].s7);
		swap(cnt[rt].s47,cnt[rt].s74);
		lazy[rt]^=1;
		return;
	}
	push_down(rt);
	int mid=(l+r)/2;
	if(y<=mid){
		update(rt*2,l,mid,x,y);
	}
	else if(x>mid){
		update(rt*2+1,mid+1,r,x,y);
	}
	else{
		update(rt*2,l,mid,x,mid);
		update(rt*2+1,mid+1,r,mid+1,y);
	}
	push_up(rt);
}

int main(){
	cin>>n>>m;
	cin>>str;
	build(1,1,n);
	for(int i=1;i<=m;i++){
		cin>>str;
		if(str=="count"){
			cout<<cnt[1].s47<<endl;
		}
		else{
			cin>>x>>y;
			update(1,1,n,x,y);
		}
	}
}
