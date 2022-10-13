/*Author��AustinJiang
��Ŀ���߶���֮������� 
ʱ�临�Ӷȣ�O(q*log(n))
�㷨����״���飬��� */
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
const int N=1e5+10;

int n,q,d[N][2];

int lowbit(int x){
	return x&-x;
}

void update(int x,int v){
	for(int i=x;i<=n;i+=lowbit(i)) d[i][0]+=v,d[i][1]+=v*x;
}

int query(int x,int k){
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i)) ans+=d[i][k];
	return ans;
}

int get_sum(int x){
	return (x+1)*query(x,0)-query(x,1);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1,x,last=0;i<=n;i++){
		cin>>x;
		update(i,x-last);
		last=x;
	}
	for(int i=1;i<=q;i++){
		char opt;
		int a,b,c;
		cin>>opt>>a>>b;
		if(opt=='C') cin>>c,update(a,c),update(b+1,-c);
		else cout<<get_sum(b)-get_sum(a-1)<<endl;
	}
	return 0;
}

