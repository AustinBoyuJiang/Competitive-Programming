#include<bits/stdc++.h>
using namespace std;
int n,x;
string opt;
queue<int>q;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>opt;
		if(opt=="push"){
			cin>>x;
			q.push(x); 
		}
		else if(opt=="pop"){
			if(!q.empty()) q.pop();
		}
		else if(opt=="front"){
			if(q.empty()) cout<<"empty"<<endl;
			else cout<<q.front()<<endl; 
		}
		else if(opt=="back"){
			if(q.empty()) cout<<"empty"<<endl;
			else cout<<q.back()<<endl;
		}
		else if(opt=="size"){
			cout<<q.size()<<endl;
		}
	}
	return 0;
}
