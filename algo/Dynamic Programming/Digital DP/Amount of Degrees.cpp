#include<bits/stdc++.h>
#define int long long
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
#define QG priority_queue<int,vector<int>,greater<int> >
#define QL priority_queue<int,vector<int>,less<int> >
using namespace std;
const int INF=LLONG_MAX;
const int N=50;

//f[i][j]表示长度为i有j个1的数量 
int x,y,k,b,f[N][N];

void init(){
	for(int i=0;i<N;i++)
		f[i][0]=1;
	for(int i=1;i<N;i++) for(int j=1;j<=i;j++)
		f[i][j]=f[i-1][j]+f[i-1][j-1];
}

int cal(int x){
	int ans=0,cnt=0,digit[N];
	while(x){
		digit[++cnt]=x%b;
		x/=b;
	}
	for(int i=cnt;i>0;i--)
		if(digit[i]<2) ans+=(1<<i-1)*digit[i];
		else{
			for(int j=0;j<i;j++)
				ans+=1<<j;
			break;
		}
	return ans;
}

int solve(int x) {
    int tot=0,ans=0;
    for(int i=31;i>0;i--){
        if(1<<i&x){
            tot++;
            if(tot>k) break;
            x^=(1<<i);
        }
        if(1<<i-1&x) ans+=f[i-1][k-tot];
    }
    if(tot+x==k) ans++;
    return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	cin>>x>>y>>k>>b;
	cout<<solve(cal(y))-solve(cal(x-1))<<endl;
	return 0;
}

