#include<bits/stdc++.h>
#define ll long long
#define lb long double
#define pf push_front
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PI pair<int, int>
#define VI vector<int>
using namespace std;
const int N=15;

//dp[i][0/1]:前i位的方案数，第i位是否为6 
int a,b,digit[N],dp[N][2];

int dfs(int pos,int is6,int isMax){
	if(!pos) return 1;
	if(!isMax&&dp[pos][is6]>0) return dp[pos][is6];
	int sum=0,MaxNum=isMax?digit[pos]:9;
	for(int i=0;i<=MaxNum;i++){
		if((is6&&i==2)||i==4) continue;
		sum+=dfs(pos-1,i==6,isMax&&i==MaxNum);
	}
	if(!isMax) dp[pos][is6]=sum;
	return sum;
}

int get_sum(int x){
	int cnt=0;
	while(x){
		digit[++cnt]=x%10;
		x/=10;
	}
	return dfs(cnt,0,1);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(~scanf("%d %d",&a,&b)){
		if(a==0&&b==0) break;
		cout<<get_sum(b)-get_sum(a-1)<<endl;
	}
	return 0;
}

