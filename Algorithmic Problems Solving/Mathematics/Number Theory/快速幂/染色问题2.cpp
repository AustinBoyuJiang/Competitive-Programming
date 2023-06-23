/*Author：AustinJiang
题目：染色问题2
时间复杂度：O(log(m))
算法：快速幂，数学
来源：jmcoding
思路：(m-1)^n+(-1)^n*(m-1)种染色法
n片区域，m种颜色有a(n)种染色法，A(n)为n区域n
由于相邻区域颜色不能相同，A(1)有m种染法，A(2)到A(n)各有m-1种染法 
其中分为两类，A(1)和A(n)相色与不同色 
同色时可以把A(1)和A(n)看成一个区域，此时有a(n-1)种染法
因此可以得出a(n)=m*(m-1)^(n-1)-a(n-1)，a(2)=m*(m-1)
a(n)=m*(m-1)^(n-1)-a(n-1)两边同时减去 (m-1)得出 a(n)-(m-1)^n=m*(m-1)^(n-1)-(m-1)^n-a(n-1)
将 m*(m-1)^(n-1)-(m-1)^n转换
m*((m-1)^n/(m-1))-(m-1)^n
(m-1)^n*(m/(m-1)-1)
(m-1)^n*(m/(m-1)-(m-1)/(m-1))
(m-1)^n*((m-(m-1))/(m-1))
(m-1)^n*(1/(m-1))
(m-1)^n/(m-1)
(m-1)^(n-1)
得出新公式 a(n)-(m-1)^n=(m-1)^(n-1)-a(n-1)，继续转换 
a(n)+a(n-1)=(m-1)^n+(m-1)^(n-1)，因此
a(n-1)+a(n-2)=(m-1)^(n-1)+(m-1)^(n-2)，两个公式相减 
a(n)+a(n-1)-a(n-1)-a(n-2)=(m-1)^n+(m-1)^(n-1)-(m-1)^(n-1)-(m-1)^(n-2)
得出 a(n)-a(n-2)=(m-1)^n-(m-1)^(n-2)
a(n)-(m-1)^n=-(m-1)^(n-2)+a(n-2)
所以 
a(n)-(m-1)^n=(m-1)^(n-1)-a(n-1)
			=-(m-1)^(n-2)+a(n-2)
			=(-1)^2*(a(n-2)-(m-1)^(n-2))
			=(-1)^3*(a(n-3)-(m-1)^(n-3))
			=(-1)^(n-3)*(a(3)-(m-1)^3)
			=(-1)^(n-2)*(a(2)-(m-1)^2)
将a(2)带入成 m*(m-1)
(-1)^(n-2)*(m*(m-1)-(m-1)^2)
(-1)^(n-2)*(m*(m-1)-(m-1)*(m-1)) 
(-1)^(n-2)*((m-1)*(m-(m-1)))
(-1)^(n-2)*((m-1)*(m-m+1))
(-1)^(n-2)*((m-1)*1)
(-1)^(n-2)*(m-1)
(-1)^n/(-1)^2*(m-1)
(-1)^n/1*(m-1)
(-1)^n*(m-1)
所以a(n)-(m-1)^n=(-1)^n*(m-1)
a(n)=(-1)^n*(m-1)+(m-1)^n
最终得出 a(i)=(m-1)^n+(-1)^n*(m-1) */
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
const int MOD=1e9+7;

int n,m;

int pow(int a,int b){
	int ans=1;
	while(b){
		if(b%2) ans*=a,ans%=MOD;
		a*=a,a%=MOD;
		b/=2;
	}
	return ans;
}

//int a(int n){
//	if(n==2) return m*(m-1)%MOD;
//	return (m*pow(m-1,n-1)-a(n-1))%MOD;
//}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cout<<pow(m-1,n)+(n&1?-1:1)*(m-1)<<endl;
	return 0;
}

