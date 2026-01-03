#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<pair<int,int>>;
template <class T> using PQ = priority_queue<T>; 
template <class T> using PQG = priority_queue<T,vector<T>,greater<T>>;

const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const char nl = '\n';
constexpr array<pair<int,int>,8> dir = {{
    {1,0}, {0,1}, {0,-1}, {-1,0},
    {1,1}, {1,-1}, {-1,1}, {-1,-1}
}};
const int MOD = 998244353;

template<class T> inline bool chkmax(T &a, const T &b){ 
    if(b > a){ a = b; return true; } 
    return false; 
}

template<class T> inline bool chkmin(T &a, const T &b){ 
    if(b < a){ a = b; return true; } 
    return false; 
}

const int N = 1e6+10;

int a,b,c;

void check1(int a,int b,int c,char M,char I,char T){
		if(b>=c){
			rep(i,1,b-c){
				cout<<M<<I;
				a--;
			}
			b=c;
		}
		
		else{
			rep(i,1,c-b){
				cout<<M<<T;
				a--;
			}
			c=b;
		}
			int k=min(a,b+c);
			if(k%2==1) k--;
			bool lst=0;
			rep(i,1,k){
				cout<<M;
					if(i<=k/2){
						cout<<I;
						b--;
					}
					else{
						cout<<T;
						c--;
					}
				a--;
			}
			rep(i,1,a){
				lst=1;
				cout<<M;
			}
			while(b>0||c>0){
				if(lst){
					
					if(b>0){
						cout<<T; 
						b--;
					}
					if(c>0){
						cout<<I; 
						c--;
					}
				}
				else{
					if(c>0){
						cout<<I; 
						c--;
					}
					if(b>0){
						cout<<T; 
						b--;
					}
				}
			}
			cout<<endl;
			return;
}



void check2(int a,int b,int c,char M,char I,char T){
	if(not(a==0||c==0)){
		if(b>a+c){
			cout<<"NO"<<endl;
			return;
		}
		cout<<"YES"<<endl;
		int kk=a+c-b;
		rep(i,1,a-kk/2){
			if(i==1&&kk%2==1){
				cout<<M;
			}
			else cout<<I<<M;
		}
		rep(i,1,kk/2){
			cout<<T<<M;
		}
		rep(i,1,c-kk/2){
			cout<<T<<I;
		}
		cout<<endl;
		return;
		
	}
	cout<<"YES"<<endl;
		int k=abs(a-c)+(b-abs(a-c))/2;
		int kk=(b-abs(a-c))/2+(a-c);
		rep(i,1,k){
			cout<<I;
			if(i<=kk){
				cout<<M;
				a--;
			}
			else{
				cout<<T;
				c--;
			}
			b--;
		}
		rep(i,1,b){
			cout<<I;
		}
		while(a>0||c>0){
			if(a>0){
				cout<<M; 
				a--;
			}
			if(c>0){
				cout<<T; 
				c--;
			}
		}
		cout<<endl;
		return;
}

void SOLVE(int Case){
	cin>>a>>b>>c;
	if(c>a+b+1||a>b+c+1||b>a+c+1){
		cout<<"NO"<<endl;
		return;
	}
	if(a>=b&&a>=c){
		cout<<"YES"<<endl;
		check1(a,b,c,'M','I','T');
	}
	else if(c>=a&&c>=b){
		cout<<"YES"<<endl;
		check1(c,b,a,'T','I','M');
	}
	else if(b>=a&&b>=c){
		check2(a,b,c,'M','I','T');
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("in.txt","r",stdin);
	//freopen("stdout.txt","w",stdout);
	int T=1;
	cin>>T;
	for (int i = 1; i <= T; i++) SOLVE(i);
	return 0;
}