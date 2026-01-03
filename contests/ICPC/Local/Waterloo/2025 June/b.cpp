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

const int N = 510;

int t,n;

struct node{
	int x,y,c,r;
} a[N],b[N];

signed main(){
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		rep(i,1,n){
			cin>>a[i].x>>a[i].y>>a[i].c>>a[i].r;
		}
		rep(i,1,m){
			cin>>b[i].x>>b[i].y>>b[i].c;
		}
		rep(j,1,m){
			int d=(a[1].x-b[j].x)*(a[1].x-b[j].x)+(a[1].y-b[j].y)*(a[1].y-b[j].y);
			if(d<=a[i].r*a[i].r){
				a[i].c+=b[j].c;
				b[j].c=0; 
			}
		}
		rep(i,1,n){
			rep(j,1,m){
				int d=(a[i].x-b[j].x)*(a[i].x-b[j].x)+(a[i].y-b[j].y)*(a[i].y-b[j].y);
				if(d<=a[i].r*a[i].r){
					a[i].c+=b[j].c;
				}
			}
		}
		int ans=1;
		rep(i,1,n){
			if(a[1].c<a[i].c){
				ans=0;
				break;
			}
		}
		if(ans==1){
			cout<<"Suiting Success"<<endl;
		}
		else{
			cout<<"Lonesome Willy"<<endl;
		}
	}
}

