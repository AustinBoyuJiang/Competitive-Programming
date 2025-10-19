#include<bits/stdc++.h>
using namespace std;

const int E=100010;

int l,n,f,b,cnt,pos,res[E];

struct point{
	int dis,value;
}stop[E];

stack<int>stk;
int main(){
	cin>>l>>n>>f>>b;
	
	for(int i=0;i<n;i++){
		cin>>stop[i].dis>>stop[i].value;		
		while(!stk.empty() && stop[i].value > stop[stk.top()].value) {
			res[stk.top()] = i;
			stk.pop();
		}
		stk.push(i); 
	}
	while(not(stk.empty())){
		int top=stk.top();
		stk.pop();
		res[top]=top;
	}
	for(int i=0;i<n;i++){
		if(i==res[i]){
			cnt+=(stop[i].dis-pos)*(f-b)*stop[i].value;
			pos = stop[i].dis;
		}
	}
	cout<<cnt<<endl;
}
