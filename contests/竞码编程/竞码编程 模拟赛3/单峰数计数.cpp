/*Author：AustinJiang
题目：单峰数计数
时间复杂度：O(log(n))
算法：快速幂 
来源：竞码编程 模拟赛3
思路：∑[i=0~n-1] c(i,n-1)
n--, f[i]=f[i-1]+p(i,n)/i!
2^(m-1) */
#pragma GCC optimize(2)
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
const int N=1e5+10;
const int MOD=1234567;

int n;

int quick_pow(int a,int b){
	int ans=1;
	while(b){
		if(b%2) ans*=a,ans%=MOD;
		a*=a,a%=MOD;
		b/=2;
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cout<<quick_pow(2,n-1)<<endl;
	return 0;
}

