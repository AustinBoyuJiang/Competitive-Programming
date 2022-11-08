/*Author：AustinJiang
题目：DNA
时间复杂度：O()
算法：
来源：
思路：
*/
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
const int N=5e6+10;
const int MOD=5e6+7;
const int base=13531;

int n,k,ans,a[N],hs[N],power[N],cnt[MOD];
string dna;

int HASH(int l,int r){
	return ((hs[r]-(hs[l-1]*power[r-l+1])%MOD)%MOD+MOD)%MOD;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>dna>>k;
	n=dna.size();
	power[0]=1;
	for(int i=1;i<=n;i++)
		power[i]=(power[i-1]*base)%MOD;
	for(int i=0;i<n;i++)
		hs[i]=(hs[i-1]*base+dna[i]-'A')%MOD;
	for(int i=0;i+k<=n;i++){
		cnt[HASH(i,i+k-1)]++;
		ans=max(ans,cnt[HASH(i,i+k-1)]);
	}
	cout<<ans<<endl;
	return 0;
}

