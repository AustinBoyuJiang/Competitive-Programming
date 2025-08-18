/*Author：AustinJiang
题目：Bag of mice
时间复杂度：O(n^2)
算法：概率DP 
来源：CF148D */
#pragma GCC optimize(2)
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

int b,w;
double dp[N][N][0];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>w>>b;
	for(int i=1;i<=w;i++)
		dp[i][0][0]=1;
	for(int i=1;i<=w;i++){
		for(int j=1;j<=b;j++){
			dp[i][j][0]=(i+j*dp[i][j-1][1])/(i+j);//公主获胜概率 
			dp[i][j][1]=(i*dp[i-1][j-1][0]+(j-1)*dp[i][j-2][0])/(i+j-1)*j/(i+j);//龙失败概率 
		}
	}
	cout<<dp[w][b][0]<<endl;
	return 0;
}

