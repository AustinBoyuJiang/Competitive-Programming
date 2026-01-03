#include<bits/stdc++.h>
using namespace std;
deque<int>q;
int n,p,c;
int main(){
	c=0;
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		q.push_front(i);
	}
	while(!q.empty()){
		c++;
		if(c%p==0){
			cout<<q.back()<<' ';
		}
		else{
			q.push_front(q.back());
		}
		q.pop_back();
	}
}
