#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define endl '\n'

int n,m;

signed main(){
	cin>>n>>m;
	rep(i,1,n){
		vector<int> cnt(26);
		string s;
		cin>>s;
		for(char x:s){
			cnt[x-'a']++;
		}
		bool ans=1;
		rep(i,1,m-1){
			if((cnt[s[i]-'a']>1)==(cnt[s[i-1]-'a']>1)){
				ans=0;
				break; 
			}
		}
		if(ans){
			cout<<"T"<<endl;
		}
		else{
			cout<<"F"<<endl;
		}
	}
	return 0;
}

