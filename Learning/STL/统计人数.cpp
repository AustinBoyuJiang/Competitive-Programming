/*Author：AustinJiang
题目：统计人数 
时间复杂度：O(n)
算法：STL,DFS */
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
const int N=1e5+10;

int n,ans;
map<string,string> name;
map<string,int> flag;

string find(string x){
	flag[x]=0;
	if(name[x]=="") return x;
	return name[x]=find(name[x]);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		name[a]=b;
		flag[a]=1;
	}
	for(auto x:name)
		if(flag[x.fir]) name[x.fir]=find(x.sec);
	for(auto x:flag)
		if(x.sec) ans++;
	cout<<ans<<endl;
	for(auto x:flag)
		if(x.sec) cout<<x.fir<<' '<<name[x.fir]<<endl;
	return 0;
}


