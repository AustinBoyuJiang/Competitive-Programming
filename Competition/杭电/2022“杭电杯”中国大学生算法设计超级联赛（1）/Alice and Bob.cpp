/*
 * Author: Austin Jiang
 * Date: 7/18/2022 9:34:05 PM
 * Problem:
 * Description:
*/
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl '\n'
#define lc (mid<<1)
#define rc (mid<<1|1)
#define lb lower_bound
#define ub upper_bound
#define PQ priority_queue
#define random(a,b) rand()%(b-a+1)+a
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
using namespace std;
using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<PI>;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int dir[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

const int N = 1e6+10;
int T=1,n,a[N];

void solve(int Case){
	cin>>n;
	rep(i,0,n) cin>>a[i];
	ll sum=0;
	per(i,n,0){
		sum/=2;
		sum+=a[i];
		if(i<=100&&sum>=pow(2,i)){
			cout<<"Alice"<<endl;
			return;
		}
	}
	cout<<"Bob"<<endl;
}

signed main(){
	cin>>T;
	rep(Case,1,T) solve(Case);
	return 0;
}

/* stuff you should look for
    * read questions at least 3 times!!!
    * think more and then code!!!
    * partial points are GOD.
	* remember to initialize variables
    * don't stuck on one question for two long (like 30-45 min)
    * Debug: (a) read your code once, check overflow, check edge case
    * Debug: (b) create your own test case
    * Debug: (c) ╤тед
*/

