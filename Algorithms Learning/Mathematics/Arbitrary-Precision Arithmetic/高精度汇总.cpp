#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int L=1e6+10;
int A[L],B[L],ANS[L],tmp[L];

struct apa{ //arbitrary-precision arithmetic
	string num="0";
	
	apa(string num){
		this->num=num;
	}
	
	void clear(int len){
		for(int i=0;i<len;i++)
			A[i]=B[i]=ANS[i]=0;
	}
	
	void load(string x,int arr[]){
		for(int i=0;i<x.size();i++)
			arr[i]=x[x.size()-i-1]-'0';
	}
	
	void store(int len,string &x,int arr[]){
		x="";
		while(len>1&&!arr[len-1]) len--;
		for(int i=len-1;i>=0;i--)
			x=x+to_string(arr[i]);
	}
	
	bool operator> (const apa &other){
		string a=this->num,b=other.num;
		if(a.size()<b.size()) return 0;
		if(a.size()>b.size()) return 1;
		int len=a.size();
		for(int i=0;i<len;i++){
			if(a[i]<b[i]) return 0;
			if(a[i]>b[i]) return 1;
		}
		return 0;
	}
	
	bool operator>= (const apa &other){
		string a=this->num,b=other.num;
		if(a.size()<b.size()) return 0;
		if(a.size()>b.size()) return 1;
		int len=a.size();
		for(int i=0;i<len;i++){
			if(a[i]<b[i]) return 0;
			if(a[i]>b[i]) return 1;
		}
		return 1;
	}
	
	bool operator< (const apa &other){
		string a=this->num,b=other.num;
		if(a.size()<b.size()) return 1;
		if(a.size()>b.size()) return 0;
		int len=a.size();
		for(int i=0;i<len;i++){
			if(a[i]<b[i]) return 1;
			if(a[i]>b[i]) return 0;
		}
		return 0;
	}
	
	bool operator<= (const apa &other){
		string a=this->num,b=other.num;
		if(a.size()<b.size()) return 1;
		if(a.size()>b.size()) return 0;
		int len=a.size();
		for(int i=0;i<len;i++){
			if(a[i]<b[i]) return 1;
			if(a[i]>b[i]) return 0;
		}
		return 1;
	}
	
	apa operator+ (const apa &other){
		string a=this->num,b=other.num;
		int lena=a.size(),lenb=b.size(),len;
		clear(len=max(lena,lenb)+1);
		load(a,A),load(b,B);
		for(int i=0;i<len;i++){
			ANS[i]+=A[i]+B[i];
			if(ANS[i+1]>9){
				ANS[i]-=10;
				ANS[i+1]++;
			}
		}
		string ans;
		store(len,ans,ANS);
		return (apa)ans;
	}
	
	apa operator+= (const apa &other){
		apa a(this->num),b(other.num);
		return (apa)(this->num=(a+b).num);
	}
	
	apa operator- (const apa &other){
		string a=this->num,b=other.num;
		int lena=a.size(),lenb=b.size(),len;
		clear(len=max(lena,lenb));
		load(a,A),load(b,B);
		for(int i=0;i<len;i++){
			ANS[i]+=A[i]-B[i];
			if(ANS[i]<0){
				ANS[i]+=10;
				ANS[i+1]--;
			}
		}
		string ans;
		store(len,ans,ANS);
		return (apa)ans;
	}
	
	apa operator-= (const apa &other){
		apa a(this->num),b(other.num);
		return (apa)(this->num=(a-b).num);
	}
	
	apa operator* (const apa &other){
		string a=this->num,b=other.num;
		int lena=a.size(),lenb=b.size(),len;
		clear(len=lena+lenb);
		load(a,A),load(b,B);
		for(int i=0;i<lena;i++)
			for(int j=0;j<lenb;j++)
				ANS[i+j]+=A[i]*B[j];
		for(int i=0;i<len;i++){
			ANS[i+1]+=ANS[i]/10;
			ANS[i]%=10;
		}
		string ans;
		store(len,ans,ANS);
		return (apa)ans;
	}
	
	apa operator*= (const apa &other){
		apa a(this->num),b(other.num);
		return (apa)(this->num=(a*b).num);
	}
	
	apa operator/ (const apa &other){
		string a=this->num,b=other.num;
		int len=a.size();
		apa now("0");
		for(int i=0;i<len;i++){
			now=now*(apa)"10"+(apa)to_string(a[i]-'0');
			tmp[len-i-1]=0;
			while(now>=other){
				now-=other;
				tmp[len-i-1]++;
			}
		}
		string ans;
		store(len,ans,tmp);
		return (apa)ans;
	}
	
	apa operator/= (const apa &other){
		apa a(this->num),b(other.num);
		return (apa)(this->num=(a/b).num);
	}
	
	apa operator% (const apa &other){
		apa a(this->num),b(other.num);
		return a-b*(a/b);
	}
	
	apa operator%= (const apa &other){
		apa a(this->num),b(other.num);
		return (apa)(this->num=(a%b).num);
	}
	
	apa operator^ (const apa &other){
		apa a(this->num),b(other.num),ans("1");
		while(b.num!="0"){
			if((b%((apa)"2")).num=="1")
				ans*=a;
			a*=a;
			b/=(apa)"2";
		}
		return ans;
	}
	
	apa operator^= (const apa &other){
		apa a(this->num),b(other.num);
		return (apa)(this->num=(a^b).num);
	}
	
	apa sqrt(){
		apa a(this->num),ans("");
		int len=(a.num.size()-1)/2+1;
		for(int i=0;i<len;i++) ans.num+="0";
		for(int i=0;i<len;i++){
			for(int j=1;j<=9;j++){
				ans.num[i]++;
				if((ans^(apa)"2")>a){
					ans.num[i]--;
					break;
				}
			}
		}
		return ans;
	}
};

signed main(){
	string a,b;
	cin>>a>>b;
	cout<<((apa)a%(apa)b).num<<endl;
	return 0;
}

