/*Author：AustinJiang
题目：子串查找(哈希&&KMP)
时间复杂度：O(n+m)
算法：字符串，KMP */
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
const int N=1e6+10;

int ans,Next[N];
string a,b;

void init(string b){
	int n=b.size();
	Next[0]=-1;
	for(int i=1;i<n;i++){
		int j=Next[i-1];
		while(j>=0&&b[j+1]!=b[i]) j=Next[j];
		if(b[j+1]==b[i]) j++;
		Next[i]=j;
	}
}

void KMP(string a,string b){
	int n=a.size(),m=b.size(),j=-1;
	for(int i=0;i<n;i++){
		while(j>=0&&b[j+1]!=a[i]) j=Next[j];
		if(b[j+1]==a[i]) j++,ans+=j+1==m;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b;
	init(b);
	KMP(a,b);
	cout<<ans<<endl;
	return 0;
}

