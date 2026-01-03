#pragma GCC optimize(2)

#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'

#define fir first
#define sec second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<PI>;
template <class T> using Vec = vector<T>;
template <class T> using PQ = priority_queue<T>;
template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;

const int INF = 0x3f3f3f3f;

const int N = 1e6+10;

int n,p;
string s;

signed main(){
	cin>>s>>p;
	Vec<pair<char,int>> v;
	for(char c:s){
		if('a'<=c&&c<='z'){
			v.pb({c,0});
		}
		else{
			v[(int)v.size()-1].sec*=10;
			v[(int)v.size()-1].sec+=c-'0';
		}
	}
	for(auto p:v){
		n+=p.sec;
	}
	p=p%n+1;
	int i=0;
	while(v[i].sec<p){
		p-=v[i].sec;
		i++;
	}
	cout<<v[i].fir<<endl;
}

