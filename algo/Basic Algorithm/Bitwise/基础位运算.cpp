#include<bits/stdc++.h>
#define ll long long
#define lb long double
#define pf push_front
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define for(i,n) for(int i=1;i<=n;i++)
#define PI pair<int, int>
#define VI vector<int>
using namespace std;

int m,o,x,k;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m;
	for(i,m){
		cin>>o>>x;
		if(o==7|o==8|o==9|o==11|o==12|o==13|o==14) cin>>k;
		if(o==1) printf("%d\n",x>>1);
		if(o==2) printf("%d\n",x<<1);
		if(o==3) printf("%d\n",x<<1|1);
		if(o==4) printf("%d\n",(x|1)-1);
		if(o==5) printf("%d\n",x|1);
		if(o==6) printf("%d\n",x^1);
		if(o==7) printf("%d\n",x|(1<<k-1));
		if(o==8) printf("%d\n",x&~(1<<k-1));
		if(o==9) printf("%d\n",x^(1<<k-1));
		if(o==10) printf("%d\n",x^(x>>3<<3));
		if(o==11) printf("%d\n",x^(x>>k<<k));
		if(o==12) printf("%d\n",(x^x>>k<<k)>>k-1);
		if(o==13) printf("%d\n",x|(1<<k)-1);
		if(o==14) printf("%d\n",x^(1<<k)-1);
		if(o==15) printf("%d\n",x&x+1);
		if(o==16) printf("%d\n",x|x+1);
		if(o==17) printf("%d\n",x|x-1);
		if(o==18) printf("%d\n",(x^x+1)>>1);
		if(o==19) printf("%d\n",x&-x);
	}
	return 0;
}

