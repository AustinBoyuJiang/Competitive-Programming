/*Author: AustinJiang
题目: 辗转相除法 
时间复杂度: O(log(a))
算法: */
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

int a,b;

int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b;
	cout<<gcd(a,b)<<endl; 
	return 0;
}

