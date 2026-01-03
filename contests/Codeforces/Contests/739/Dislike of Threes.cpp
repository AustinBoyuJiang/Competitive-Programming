/*Author：AustinJiang
题目：Dislike of Threes
时间复杂度：O(1000)
算法：枚举 
来源：Codeforces Round #739 (Div. 3)*/
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
const int N=1e3+10;

int t,k,num,tot,f[N];

void init(){
	while(tot<=1000){
		num++;
		if(num%3&&num%10!=3) f[++tot]=num;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>k;
		cout<<f[k]<<endl;
	}
	return 0;
}

