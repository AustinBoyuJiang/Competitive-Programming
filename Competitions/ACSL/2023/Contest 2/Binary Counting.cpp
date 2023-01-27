#include <bits/stdc++.h>

using namespace std;



using VI = vector<int>;

#define pb push_back
#define all(v) begin(v),end(v)
#define rep(i,x,y) for(int i=x;i<=(y);i++)
#define per(i,x,y) for(int i=x;i>=(y);i--)

/*
 * Complete the 'findLastOctal' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
 
bool remove(VI &num,int base,int x){
    VI flag(num.size());
    deque<int> tar,now;
    if(x==0) tar.pb(0);
    while(x){
        tar.pb(x%base);
        x/=base;
    }
    reverse(all(tar));
    if(tar.size()>num.size()) return 0;
    rep(i,0,(int)tar.size()-1) now.pb(num[i]);
    int pos=-1;
    rep(i,0,num.size()-tar.size()){
        if(now==tar){
            pos=i;
            break;
        }
        if(i+tar.size()>=num.size()) break;
        now.pop_front();
        now.pb(num[i+tar.size()]);
    }
    if(pos==-1) return 0;
    rep(i,1,tar.size()) flag[pos+i-1]=1;
    VI tmp;
    rep(i,0,num.size()-1){
        if(flag[i]) continue;
        tmp.pb(num[i]);
    }
    num=tmp;
    
    now.clear();
    if(tar.size()>num.size()) return 1;
    rep(i,0,(int)tar.size()-1) now.pb(num[i]);
    pos=-1;
    rep(i,0,num.size()-tar.size()){
        if(now==tar) pos=i;
        if(i+tar.size()>=num.size()) break;
        now.pop_front();
        now.pb(num[i+tar.size()]);
    }
    if(pos==-1) return 1;
    fill(all(flag),0);
    rep(i,1,tar.size()) flag[pos+i-1]=1;
    tmp.resize(0);
    rep(i,0,num.size()-1){
        if(flag[i]) continue;
        tmp.pb(num[i]);
    }
    num=tmp;
    return 1;
}
 
int findLastOctal(string s) {
    VI num;
    for(int x:s){
        VI tmp;
        rep(i,1,8){
            tmp.pb(x&1);
            x>>=1;
        }
        reverse(all(tmp));
        for(auto x:tmp){
            num.pb(x);
        }
    }
    int cnt;
    cnt=0; while(remove(num,2,cnt++)){}
    VI tmp;
    for(int i=num.size()-1;i>=0;i-=3){
        int x=(i-2>=0?num[i-2]:0)*4+(i-1>=0?num[i-1]:0)*2+num[i];
        tmp.pb(x);
    }
    while(tmp[tmp.size()-1]==0){
        tmp.pop_back();
    }
    reverse(all(tmp));
    num=tmp;
    cnt=0; while(remove(num,8,cnt++)){}
    return cnt-2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = findLastOctal(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

