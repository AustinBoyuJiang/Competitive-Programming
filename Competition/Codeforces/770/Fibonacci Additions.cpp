/*Author：AustinJiang
题目：
时间复杂度：O()
算法：
来源：
思路：
*/
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
const int N=3e5+10;

int n,q,mod,cnt,a[N],b[N],f[N],fa[N],fb[N];

void addA(int pos,int x){
	if(fa[pos]==fb[pos]) cnt++;
	fa[pos]=((fa[pos]+x)%mod+mod)%mod;
	if(fa[pos]==fb[pos]) cnt--;
}

void addB(int pos,int x){
	if(fa[pos]==fb[pos]) cnt++;
	fb[pos]=((fb[pos]+x)%mod+mod)%mod;
	if(fa[pos]==fb[pos]) cnt--;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q>>mod;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]%=mod;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		b[i]%=mod;
	}
	f[1]=1;
	for(int i=2;i<=n+2;i++)
		f[i]=(f[i-1]+f[i-2])%mod;
	fa[1]=a[1];
	for(int i=2;i<=n+2;i++)
		fa[i]=((a[i]-a[i-1]-a[i-2])%mod+mod)%mod;
	fb[1]=b[1];
	for(int i=2;i<=n+2;i++)
		fb[i]=((b[i]-b[i-1]-b[i-2])%mod+mod)%mod;
	for(int i=1;i<=n+2;i++)
		if(fa[i]!=fb[i]) cnt++;
	for(int i=1;i<=q;i++){
		char opt;
		int l,r;
		cin>>opt>>l>>r;
		if(opt=='A'){
			addA(l,1);
			addB(r+1,f[r-l+2]);
			addB(r+2,f[r-l+1]);
		}
		else{
			addB(l,1);
			addA(r+1,f[r-l+2]);
			addA(r+2,f[r-l+1]);
		}
		if(!cnt) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

