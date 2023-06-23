#include<bits/stdc++.h>
using namespace std;
stack<int>input;
stack<int>output;
int n,inp[100010],outp[100010];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>inp[i];
	}
	for(int i=0;i<n;i++){
		cin>>outp[i];
	}
	for(int i=n-1;i>=0;i--){
		output.push(outp[i]);
	}
	for(int i=0;i<n;i++){
		input.push(inp[i]);
		while(!input.empty() and input.top()==output.top()){
			input.pop();
			output.pop();
		}
	}
	if(input.empty()){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
} 
