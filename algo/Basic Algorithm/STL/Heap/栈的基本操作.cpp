#include <bits/stdc++.h>
using namespace std;
int n,x;
string opt;
stack<int>stk;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>opt;
		if(opt=="push"){
			cin>>x;
			stk.push(x);
		}
		else if(opt=="pop"){
			if(not(stk.empty())){
				stk.pop();
			}
		}
		else if(opt=="top"){
			if(stk.empty()){
				cout<<"empty"<<endl; 
			}
			else{
				cout<<stk.top()<<endl;
			}
		}
		else if(opt=="size"){
			cout<<stk.size()<<endl;
		}
	} 
	return 0;
}
