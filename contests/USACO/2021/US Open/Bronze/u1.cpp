#include<bits/stdc++.h>
using namespace std;
int n,l,ans,papers[100010];

int cmp(int a,int b){
	return a>b; 
} 

int main(){
	cin>>n>>l;
	for(int i=1;i<=n;i++){
		cin>>papers[i];
	}
	sort(papers+1,papers+n+1,cmp);
	int left=1,right=n,mid,count;
	while(left<=right){
		mid=(left+right)/2;
		count=0;
		for(int i=1;i<=mid;i++){
			count+=max(0,mid-papers[i]);
		}
		if(count<=l&&papers[mid]+1>=mid){
			ans=mid;
			left=mid+1;
		}
		else{
			right=mid-1;
		}
	}
	cout<<ans<<endl;
}
