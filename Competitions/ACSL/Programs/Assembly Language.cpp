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

int A,B,C,D,E,F,G,H,X,Y,Z,N,M;
int NUM,FACT,QUOT;

void TOP1();
void TOP2();
void NEXT();
void CONT();
void STOP();

void TOP1(){
    LOAD(NUM);
    ACC-=2;
    if(BL()) STOP();
    LOAD(2);
    STORE(FACT);
    TOP2();
}

void TOP2(){
    LOAD(NUM);
    ACC/=FACT;
    STORE(QUOT);
    ACC*=FACT;
    ACC-=NUM;
    if(BE()) NEXT();
    LOAD(FACT);
    ACC+=1;
    STORE(FACT);
    if(BU()) TOP2();
    NEXT();
}

void NEXT(){
    LOAD(FACT);
    ACC-=M;
    if(BL()) CONT();
    LOAD(FACT);
    STORE(M);
    CONT();
}

void CONT(){
    LOAD(QUOT);
    STORE(NUM);
    if(BU()) TOP1();
    STOP();
}

void STOP(){
    PRINT(M);
    END();
}

void SOLVE(int Case){
	NUM=440;
	M=0;
	TOP1();
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
