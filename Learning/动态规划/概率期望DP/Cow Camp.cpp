/*Author：AustinJiang
题目：Cow Camp
时间复杂度：O(t*log(m)^2)
算法：
来源：
思路：
*/
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define random(a,b) rand()%(b-a+1)+a
#define PQ priority_queue
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
const int INF=0x3f3f3f3f;
const int N=2010;
const int dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m;
double ans,p[N],sum[N],k[N][N],dp[N][N];

double pow(double a,int b){ //返回a^b 
	double ans=1;
	while(b){
		if(b&1) ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}

double getSum(double a,int b){ // 求 a^0+a^1+...+a^b; 
	return (1-pow(a,b+1))/(1-a);
}

double calc(double x,double a,double b,int d){ //求dp[x+d] 
	return x*pow(a,d)+b*getSum(a,d-1);
}

int find(double x,double a,double b,int l,int r){ //二分最小的d使dp[x+d]能进位
	int ans=r;
	while(l<=r){
		int mid=l+r>>1;
		if(calc(x,a,b,mid)-(int)x-1<1e-6) l=mid+1;
		else ans=mid,r=mid-1;
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	n--;
	k[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
			k[i][j]=0.5*k[i-1][j]+0.5*k[i-1][j-1];
	for(int i=0;i<=n;i++)
		p[i]=p[i-1]+k[n][i];
	for(int i=n;i>=0;i--)
		sum[i]=sum[i+1]+i*k[n][i];
	int i=0;
	while(i<m){
		double a=p[(int)ans];
		double b=sum[(int)ans+1];
		int d=find(ans,a,b,1,m-i);
		ans=calc(ans,a,b,d);
		i+=d;
	}
	printf("%.20lf\n",ans+1);
	return 0;
}

