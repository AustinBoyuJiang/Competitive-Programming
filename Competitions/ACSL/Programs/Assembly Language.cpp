/*
 * Author: Austin Jiang
 * Date: 3/21/2023 2:50:25 PM
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



namespace ASM{
	int ACC=0;
	inline void LOAD(int X){ACC=X;}
	inline void STORE(int &X){X=ACC;}
	inline bool BG(){return ACC>0;}
	inline bool BE(){return ACC==0;}
	inline bool BL(){return ACC<0;}
	inline bool BU(){return true;}
	inline void PRINT(int X){cout<<X<<endl;}
	inline void END(){exit(0);}
} using namespace ASM;

/* ========================================| Main Program |======================================== */

int T,NUM,CNT;

void TOP();
void CONT();
void STOP();

void STOP(){
	PRINT(T);
	END();
}

void CONT(){
	LOAD(CNT);
	ACC+=1;
	STORE(CNT);
	if(BU()) TOP();
	STOP();
}

void TOP(){
	STORE(CNT);
	LOAD(NUM);
	ACC/=2;
	ACC-=CNT;
	if(BL()) STOP();
	LOAD(NUM);
	ACC/=CNT;
	ACC*=CNT;
	ACC-=NUM;
	if(BL()) CONT();
	LOAD(T);
	ACC+=CNT;
	STORE(T);
	CONT();
}

void SOLVE(int Case){
	T=0;
	NUM=28;
	LOAD(1);
	TOP();
}

/* =====================================| End of Main Program |===================================== */

int main(){
	SOLVE(1);
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

