/*Author：AustinJiang
题目：Isomorphic Strings
时间复杂度：O(n*26)
算法：哈希 
来源：CF 985F */
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
const int N=2e5+10;
const int base=131;

int n,m,hs[N][30],power[N],res[2][30];
string str;

void HASH(int l,int r,bool k){
	for(int i=0;i<26;i++)
		res[k][i]=hs[r][i]-hs[l-1][i]*power[r-l+1];
	sort(res[k],res[k]+26);
}

bool check(int i,int j,int k){
	HASH(i,i+k-1,0);
	HASH(j,j+k-1,1);
	for(int i=0;i<26;i++)
		if(res[0][i]!=res[1][i]) return 0;
	return 1;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>str;
	for(int i=0;i<26;i++)
		for(int j=1;j<=n;j++)
			hs[j][i]=hs[j-1][i]*base+(str[j-1]-'a'==i);
	power[0]=1;
	for(int i=1;i<=n;i++)
		power[i]=power[i-1]*base;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		cout<<(check(x,y,z)?"YES":"NO")<<endl;
	}
	return 0;
}

