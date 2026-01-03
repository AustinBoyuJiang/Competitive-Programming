/*Author：AustinJiang
题目：网络连接 
时间复杂度：O(n)
算法：STL
来源：CSP 2021 J2 */
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define endl "\n"
#define random(a,b) rand()%(b-a+1)+a
#define PI pair<int,int>
#define VI vector<int>
#define VPI vector<PI>
#define PQ priority_queue
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e3+10;

int n;
map<string,int> servers;

bool check(string ip){
	int res=0,i,cnt1=0,cnt2=0,flag=0,cnt3=0;
	for(i=0;i<ip.size();i++){
		if(ip[i]=='.'||ip[i]==':'){
			if(flag==1&&cnt3>0) return 0;
			if(flag==0&&cnt3>1) return 0;
			if(res==0&&cnt3==0) return 0;
			if(res>255) return 0;
			res=0;
			flag=0;
			cnt1++;
			cnt3=0;
			if(ip[i]==':'){
				cnt2++;
				break;
			}
		}
		else{
			if(ip[i]-'0'>0) flag=1;
			else if(!flag) cnt3++;
			res*=10;
			res+=ip[i]-'0';
		}
	}
	flag=0,cnt3=0;
	for(i++;i<ip.size();i++){
		if(ip[i]-'0'>0) flag=1;
		else if(!flag) cnt3++;
		res*=10;
		res+=ip[i]-'0';
	}
	if(flag==1&&cnt3>0) return 0;
	if(flag==0&&cnt3>1) return 0;
	if(res==0&&cnt3==0) return 0;
	return res<=65535&&cnt1==4&&cnt2==1;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		string type,ip;
		cin>>type>>ip;
		if(check(ip)){
			if(type=="Server"){
				if(servers[ip]) cout<<"FAIL"<<endl;
				else servers[ip]=i,cout<<"OK"<<endl;
			}
			else{
				if(servers[ip]) cout<<servers[ip]<<endl;
				else cout<<"FAIL"<<endl;
			}
		}
		else cout<<"ERR"<<endl;
	}
	return 0;
}

