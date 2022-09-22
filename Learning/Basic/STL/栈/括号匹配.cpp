#include<bits/stdc++.h>
using namespace std;
int main(){
	stack<char>brackets;
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(!brackets.empty() and str[i]==')' and brackets.top()=='('){
			brackets.pop();
		}
		else{
			brackets.push(str[i]);
		}
	}
	if(brackets.empty()){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
}
