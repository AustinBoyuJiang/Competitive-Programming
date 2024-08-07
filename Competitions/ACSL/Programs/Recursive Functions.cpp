/*
 * Author: Austin Jiang
 * Date: 5/10/2023 9:36:18 PM
 * Problem:
 * Source:
 * Description:
*/

/* Configuration */
//#define MULTICASES
//#define LOCAL
//#define READLOCAL
//#define FILESCOMP
//#define SETMEM
#define FASTIO
//#define OPTIMIZE
//#define INTTOLL

#ifdef OPTIMIZE
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#endif

#include<bits/stdc++.h>
using namespace std;

#ifdef INTTOLL
#define int long long
#endif

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'

/* Pair */
#define fir first
#define sec second

/* Segment Tree */
#define lc (rt << 1)
#define rc (rt << 1 | 1)

/* STL */
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define eb emplace_back
#define ef emplace_front
#define pb push_back
#define pf push_front
#define all(v) v.begin(), v.end()

/* ========================================| Main Program |======================================== */

const int N = 1e6+10;

int n;

int f(int x,int y){
	if(x>=10){
		return f(x-2,y-3)*2+1;
	}
	if(x>4&&x<10){
		return f(y-1,x-3)-1;
	}
	assert(x<=4);
	return x*y;
}

int f(int x){
	if(x>=12) return f(x-4)-3;
	if(x>6&&x<12) return f(x-3)+2;
	assert(x<=6);
	return x*x;
}

void SOLVE(int Case){
//	cout<<f(15,11)<<endl;
	cout<<f(f(20))<<endl;
}

/* =====================================| End of Main Program |===================================== */

signed main(){
	SOLVE(1);
	return 0;
}

/* stuff you should look for
	* read questions at least 3 times!!!
    * think more and then code!!!
    * partial points are GOD.
	* remember to initialize variables
    * don't stuck on one question for two long (like 30-45 min)
    * Debug: (a) read your code once, check overflow and edge case
    * Debug: (b) create your own test case
    * Debug: (c) duipai
*/

