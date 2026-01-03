#include<bits/stdc++.h>
using namespace std;
deque<int>q;
int n,c=0,s=-1,a[1000010];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	while(s!=0){
		c++;
		q.clear();
		s=0;
		for(int i=n-1;i>=0;i--){
			if(!q.empty() and q.front()>a[i]){
				q.pop_front();
				s+=1;
			}
			q.push_front(a[i]);
		}
		n-=s;
		for(int i=0;i<n;i++){
			a[i]=q.front();
			q.pop_front();
		}
	}
	cout<<c-1<<endl;
}
