#include<bits/stdc++.h>
using namespace std;
stack<int>stk;
int a[10010],ans[10010],top,n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];		
		while(!stk.empty() && a[i] > a[stk.top()]) {
			ans[stk.top()] = i;
			stk.pop();
		}
		stk.push(i); 
	}
	while(not(stk.empty())){
		top=stk.top();
		stk.pop();
		ans[top]=n+1;
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<' '; 
	} 
	cout<<endl;
} 
