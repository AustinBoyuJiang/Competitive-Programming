/*Author：AustinJiang
题目：子串查找(哈希&&KMP)
时间复杂度：O(n)
算法：哈希 */
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
const int N=1e6+7;
const int MOD=1e9+7;
const int base=131;

int ans,lena,lenb,hs[2][N],power[N];
string a,b;

int get_hash(int l,int r){
	return (hs[1][r]-(hs[1][l-1]*power[r-l+1])%MOD+MOD)%MOD;
}

bool check(int l,int r){
	return hs[0][lena-1]==get_hash(l,r);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>b>>a;
	lena=a.size();
	lenb=b.size();
	power[0]=1;
	for(int i=1;i<=lenb;i++)
		power[i]=(power[i-1]*base)%MOD;
	for(int i=0;i<lena;i++)
		hs[0][i]=(hs[0][i-1]*base+a[i]-'a')%MOD;
	for(int i=0;i<lenb;i++)
		hs[1][i]=(hs[1][i-1]*base+b[i]-'a')%MOD;
	for(int l=0;l+lena-1<lenb;l++)
		ans+=check(l,l+lena-1);
	cout<<ans<<endl;
	return 0;
}

