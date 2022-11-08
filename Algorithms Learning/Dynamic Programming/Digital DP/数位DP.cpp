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
const int N=10;

int a,b,f[N][10];

void init(){
	f[0][0]=1;
	for(int i=1;i<N;i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<10;k++){
				if((j==6&&k==2)||j==4) continue;
				f[i][j]+=f[i-1][k];
			}
}

int get_sum(int x){
	vector<int> digit;
	while(x) {
		digit.push_back(x%10);
		x/=10;
	}
	digit.push_back(0);
	int ans=0;
	for(int i=digit.size()-2;i>=0;i--){
		for(int j=0;j<digit[i];j++){
			if(digit[i+1]==6&&j==2) continue;
			ans+=f[i+1][j];
		}
		if((digit[i+1]==6&&digit[i]==2)||digit[i]==4) break;
	} 
	
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	init();
	while(~scanf("%d %d",&a,&b)){
		if(a==0&&b==0) break;
		cout<<get_sum(b+1)-get_sum(a)<<endl;
	}
	return 0;
}

