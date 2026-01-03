#include<bits/stdc++.h>
using namespace std;
deque<char>q;
string str;
int main(){
	cin>>str;
	for(int i=0;i<str.size();i++){
		q.push_front(str[i]);
		if(q.front()=='#'){
			q.pop_front();
			q.pop_front();
		}
		else if(q.front()=='@'){
			q.clear();
		}
	}
	while(!q.empty()){
		cout<<q.back();
		q.pop_back();
	}
}
