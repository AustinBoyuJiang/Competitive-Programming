/*Author��AustinJiang
��Ŀ���ֿ�2 
ʱ�临�Ӷȣ�O(n*n^0.5*log(n^0.5))
�㷨���ֿ� */
#include<bits/stdc++.h>
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
const int N=5e4+10;

int n,sz,a[N],b[N],bl[N],lazy[N];

void resort(int i){
	int l=(i-1)*sz+1,r=min(n,i*sz);
	for(int i=l;i<=r;i++)
		b[i]=a[i];
	sort(b+l,b+r+1);
}

void update(int l,int r,int x){
	if(bl[l]==bl[r]){
		for(int i=l;i<=r;i++)
			a[i]+=x;
		resort(bl[l]);
		return;
	}
	for(int i=l;i<=bl[l]*sz;i++)
		a[i]+=x;
	resort(bl[l]);
	for(int i=(bl[r]-1)*sz+1;i<=r;i++)
		a[i]+=x;
	resort(bl[r]);
	for(int i=bl[l]+1;i<bl[r];i++)
		lazy[i]+=x;
}

int binary(int i,int x){
	int l=(i-1)*sz+1,r=min(n,i*sz);
	while(l<=r){
		int mid=(l+r)/2;
		if(b[mid]<x) l=mid+1;
		else r=mid-1;
	}
	return r-(i-1)*sz;
}

int query(int l,int r,int x){
	int ans=0;
	if(bl[l]==bl[r]){
		for(int i=l;i<=r;i++)
			if(a[i]+lazy[bl[i]]<x) ans++;
		return ans;
	}
	for(int i=l;i<=bl[l]*sz;i++)
		if(a[i]+lazy[bl[i]]<x) ans++;
	for(int i=(bl[r]-1)*sz+1;i<=r;i++)
		if(a[i]+lazy[bl[i]]<x) ans++;
	for(int i=bl[l]+1;i<bl[r];i++)
		ans+=binary(i,x-lazy[i]);
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	sz=sqrt(n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bl[i]=(i-1)/sz+1;
	}
	for(int i=1;i<=n/sz+1;i++)
		resort(i);
	for(int i=1;i<=n;i++){
		int opt,l,r,x;
		cin>>opt>>l>>r>>x;
		if(opt==0) update(l,r,x);
		else cout<<query(l,r,x*x)<<endl;
	}
	return 0;
}

