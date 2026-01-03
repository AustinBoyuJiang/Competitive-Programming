/*Author：AustinJiang
题目：Searching for Strings
时间复杂度：O(n*26)
算法：哈希，双指针 
来源：CCC 2020 Senoir */
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
const int MOD=1e9+7;
const int base=1331;

int ans,cnt[2][26],power[N],hs[N];
map<int,bool> flag;
string a,b;

bool check(){
	for(int i=0;i<26;i++)
		if(cnt[0][i]!=cnt[1][i]) return false;
	return true;
}

int get_hash(int l,int r){
	return hs[r]-(hs[l-1]*power[r-l+1]);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b;
	power[0]=1;
	for(int i=1;i<=b.size();i++)
		power[i]=power[i-1]*base;
	for(auto x:a)
		cnt[0][x-'a']++;
	for(int i=0;i<b.size();i++)
		hs[i]=hs[i-1]*base+b[i]-'a';
	for(int l=0,r=0;r<b.size();r++){
		if(r>=a.size()) cnt[1][b[l++]-'a']--;
		cnt[1][b[r]-'a']++;
		if(check()&&!flag[get_hash(l,r)]) flag[get_hash(l,r)]=1,ans++;
	}
	cout<<ans<<endl;
	return 0;
}
