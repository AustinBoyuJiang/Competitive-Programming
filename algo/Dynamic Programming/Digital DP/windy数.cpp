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
const int N=12;

int a,b,f[N][10];

void init(){
	f[0][0]=1;
	for(int i=1;i<N;i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<10;k++){
				if(abs(j-k)<2&&i!=1) continue;
				f[i][j]+=f[i-1][k];
			}
}

int get_sum(int x){
	VI digit;
	while(x) {
		digit.push_back(x%10);
		x/=10;
	}
	digit.push_back(0);
	int ans=0;
	for(int i=1;i<digit[digit.size()-2];i++)
		ans+=f[digit.size()-1][i];
	for(int i=digit.size()-3;i>=0;i--){
		for(int j=0;j<digit[i];j++){
			if(abs(digit[i+1]-j)<2) continue;
			ans+=f[i+1][j];
		}
		if(abs(digit[i+1]-digit[i])<2) break;
	}
	for(int i=1;i<=digit.size()-2;i++)
		for(int j=1;j<10;j++)
			ans+=f[i][j];
	return ans;
}

signed main(){
	init();
	scanf("%d %d",&a,&b);
	printf("%d\n",get_sum(b+1)-get_sum(a));
	return 0;
}
