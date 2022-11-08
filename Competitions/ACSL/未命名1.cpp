#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'findMatch' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING word
 *  2. STRING guesses
 */
const int N=1010;
const int A=30;

int n,cnt,lst,flag[A],flag2[A],f[A],f2[A],res[A];
string ans;

struct Words{
    int g,y,v;
    bool sg,tg;
    string str;
} words[N];

bool check(string target,int id){
    for(int i=0;i<26;i++){
        f[i]=flag[i];
        f2[i]=flag2[i];
    }
    words[id].g=words[id].y=words[id].v=0;
    words[id].sg=words[id].tg=0;
    int len=words[id].str.size();
    cout<<words[id].str<<"-------"<<endl;
    for(int i=0;i<len;i++){
        char x=words[id].str[i];
        res[x-'a']++;
        if(i<target.size()&&x==target[i]){
            words[id].g++;
            if(i==0) words[id].sg=1;
            if(i==len-1) words[id].tg=1;
        }
        if(f[x-'a']){
            words[id].y++;
            f[x-'a']--;
            cout<<i<<" "<<words[id].y<<endl;
        }
        if(f2[x-'a']){
            words[id].v++;
            f2[x-'a']--;
            // cout<<i<<" "<<words[id].y<<endl;
        }
    }
    return words[id].g||words[id].y;
}

bool cmp(Words a,Words b){
    if(a.g!=b.g) return a.g>b.g;
    if(a.y!=b.y) return a.y>b.y;
    if(a.sg!=b.sg) return a.sg>b.sg;
    if(a.tg!=b.tg) return a.tg>b.tg;
    if(a.v!=b.v) return a.v>b.v;
    return a.str<b.str;
}
 
string findMatch(string word, string guesses){
    for(auto x:word)
        flag[x-'a']++;
    for(auto x:"aeiou")
        flag2[x-'a']++;
    if(guesses[-1]!=' ') guesses+=" ";
    n=guesses.size();
    for(int i=0;i<n;i++){
        if(guesses[i]==' '){
            words[++cnt].str=guesses.substr(lst,i-lst);
            lst=i+1;
            if(!check(word,cnt)) cnt--;
        }
    }
    sort(words+1,words+cnt+1,cmp);
    cout<<word<<endl;
    for(int i=1;i<=cnt;i++){
        cout<<words[i].str<<" ";
        printf("%d %d %d %d %d\n",words[i].g,words[i].y,(int)words[i].sg,(int)words[i].tg,words[i].v);
    }
    if(cnt<6){
        for(int i=0;i<26;i++){
            if(!res[i]) ans+=i+'a';
        }
        return ans;
    }
    for(int i=1;i<=6;i++){;
        ans+=words[i].str;
        if(i<6) ans+=" ";
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string word;
    getline(cin, word);

    string guesses;
    getline(cin, guesses);

    string result = findMatch(word, guesses);

    fout << result << "\n";

    fout.close();

    return 0;
}

