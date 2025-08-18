#pragma GCC optimize(2)

#include<iostream>

using namespace std;

const int N = 1e6+10;

int n;

#include "interval_map.cpp"

interval_map<int,char> v('A'); 
signed main(){
	v.assign(1,3,'B');
	v.assign(1,2,'C');
	v.assign(2,3,'C');
	v.assign(1,3,'D');
	v.assign(3,5,'D');
	v.assign(2,4,'A');
	cout<<v[0]<<endl;
	cout<<v[1]<<endl;
	cout<<v[2]<<endl;
	cout<<v[3]<<endl;
	cout<<v[4]<<endl;
	cout<<v[5]<<endl;
	cout<<v[6]<<endl;
	cout<<v[7]<<endl;
}
