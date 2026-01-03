#include<bits/stdc++.h>
using namespace std;
int n,ans,a[20010],l[20010],r[20010];
stack<int>stk;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(!stk.empty()&&a[i]<a[stk.top()]){
			r[stk.top()]=i;
			stk.pop();
		}
		stk.push(i);
	}
	while(!stk.empty()){
		r[stk.top()]=n+1;
		stk.pop();
	}
	for(int i=n;i>=1;i--){
		while(!stk.empty()&&a[i]<a[stk.top()]){
			l[stk.top()]=i;
			stk.pop();
		}
		stk.push(i);
	}
	while(!stk.empty()){
		l[stk.top()]=0;
		stk.pop();
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,(r[i]-l[i]-1)*a[i]);
	}
	cout<<ans<<endl; 
}
