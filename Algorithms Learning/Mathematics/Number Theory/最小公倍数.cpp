/*Author：AustinJiang
题目：最小公倍数
时间复杂度：O(log(a))
算法：辗转相除法，数论 */
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

int a,b;

int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b;
	cout<<a*b/gcd(a,b)<<endl;
	return 0;
}

