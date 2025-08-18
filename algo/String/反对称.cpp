/*Author：AustinJiang
题目：反对称 
时间复杂度：O(n*log(n))
算法：字符串，哈希，二分 
来源：POI2010 */
#include<bits/stdc++.h>
#define int unsigned long long
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
const int N=5e5+10;
const int base=1331;

int n,ans,hs[N][2],power[N];
bool a[N];

int HASH(int l,int r,int k){
	if(k==0) return hs[r][k]-hs[l-1][k]*power[r-l+1];
	else return hs[l][k]-hs[r+1][k]*power[r-l+1];
}

bool check(int x,int y){
	return HASH(x-y+1,x,0)==HASH(x+1,x+y,1)&&HASH(x-y+1,x,1)==HASH(x+1,x+y,0);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		a[i]=x-'0';
	}
	power[0]=1;
	for(int i=1;i<=n;i++)
		power[i]=power[i-1]*base;
	for(int i=1;i<=n;i++)
		hs[i][0]=hs[i-1][0]*base+a[i];
	for(int i=n;i>=1;i--)
		hs[i][1]=hs[i+1][1]*base+(a[i]^1);
	for(int i=1;i<n;i++){
		int l=0,r=min(i,n-i),res;
		while(l<=r){
			int mid=l+r>>1;
			if(check(i,mid)) l=mid+1,res=mid;
			else r=mid-1;
		}
		ans+=res;
	}
	cout<<ans<<endl;
	return 0;
}

