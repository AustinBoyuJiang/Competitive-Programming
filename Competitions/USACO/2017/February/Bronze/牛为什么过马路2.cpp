/*Author：AustinJiang
题目：牛为什么过马路2 
时间复杂度：O(26^2)
算法：枚举 
来源：USACO 2017 February Bronze */
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
const int N=30;

int n,ans,pos[N][2];

bool check(int a,int b){
	if(pos[a][0]>pos[b][0]&&pos[a][0]<pos[b][1]&&pos[a][1]>pos[b][1]) return 1;
	if(pos[a][1]>pos[b][0]&&pos[a][1]<pos[b][1]&&pos[a][0]<pos[b][0]) return 1;
	return 0;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<=52;i++){
		char id;
		cin>>id;
		if(!pos[id-64][0]) pos[id-64][0]=i;
		else pos[id-64][1]=i;
	}
	for(int i=1;i<=26;i++)
		for(int j=i+1;j<=26;j++)
			if(check(i,j)) ans++;
	cout<<ans<<endl;
	return 0;
}

