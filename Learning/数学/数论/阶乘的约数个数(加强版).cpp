/*Author：AustinJiang
题目：阶乘的约数个数(加强版)
时间复杂度：O(n*sqrt(n))
算法：数论，高精度*/
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
const int N=1e3+10;

int n,len=1,cnt[N],ans[N],a[N],b[N];

void muti(int num){
	int tot=0;
	for(int i=0;i<len;i++)
		a[i]=ans[i];
	while(num){
		b[tot++]=num%10;
		num/=10;
	}
	memset(ans,0,sizeof(ans));
	for(int i=0;i<len;i++)
		for(int j=0;j<tot;j++)
			ans[i+j]+=a[i]*b[j];
	len+=tot;
	for(int i=0;i<len;i++){
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
	}
	while(len>1&&!ans[len-1]) len--;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(;n>=2;n--){
		int tmp=n,num=2;
		while(num<=sqrt(tmp)){
			if(tmp%num==0){
				tmp/=num;
				cnt[num]++;
			}
			else num++;
		}
		cnt[tmp]++;
	}
	ans[0]=1;
	for(int i=2;i<=N;i++)
		muti(cnt[i]+1);
	for(int i=len-1;i>=0;i--)
		cout<<ans[i];
	return 0;
}

