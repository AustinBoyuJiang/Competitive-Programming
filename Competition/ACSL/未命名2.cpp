#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'rotateCube' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING start
 *  2. STRING moves
 */
string ans,f[6][3][3],co[6]={"O","B","R","G","Y","P"};
pair<int,int> rules[6][2][4]={
    {{{0,0},{4,2},{5,0},{2,0}},{{0,3},{1,2},{5,1},{3,0}}},
    {{{1,0},{0,1},{3,2},{5,3}},{{1,3},{4,3},{3,3},{2,3}}},
    {{{2,0},{0,0},{5,0},{4,2}},{{2,3},{1,3},{4,3},{3,3}}},
    {{{3,0},{0,3},{1,2},{5,1}},{{3,3},{2,3},{1,3},{4,3}}},
    {{{4,0},{0,2},{2,2},{5,2}},{{4,3},{3,3},{2,3},{1,3}}},
    {{{5,0},{2,0},{0,0},{4,2}},{{5,3},{1,0},{0,1},{3,2}}}};

vector<int> locate(string start){
    for(int i=0;i<6;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(start==f[i][j][k]) return vector<int>{i,j,k};
            }
        }
    }
}

vector<int> find(int face,int dir,vector<int> pos,int step){
    vector<int> a[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            a[i][j]={face,i,j};
    
}

void solve(vector<int> pos,int dir,int cir,int step){
    string tmp;
    if(dir==0){
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                vector<int>now=find(rules[pos[0]][cir][i].first,rules[pos[0]][cir][i].second,pos,j);
                vector<int>nxt=find(rules[pos[0]][cir][(i+(j+1)/3)/4].first,rules[pos[0]][cir][(i+(j+1)/3)/4].second,pos,(j+1)%3);
                tmp=f[nxt[0]][nxt[1]][nxt[2]];
                f[nxt[0]][nxt[1]][nxt[2]]=f[now[0]][now[1]][now[2]];
            }
        }
    }
    else{
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                vector<int>nxt=find(rules[pos[0]][cir][i].first,rules[pos[0]][cir][i].second,pos,j);
                vector<int>now=find(rules[pos[0]][cir][(i+(j+1)/3)/4].first,rules[pos[0]][cir][(i+(j+1)/3)/4].second,pos,(j+1)%3);
                tmp=f[nxt[0]][nxt[1]][nxt[2]];
                f[nxt[0]][nxt[1]][nxt[2]]=f[now[0]][now[1]][now[2]];
            }
        }
    }
}

string rotateCube(string start, string moves){
    for(int i=0;i<6;i++){
        int num=0;
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                f[i][j][k]=co[i]+to_string(num);
                num++;
            }
        }
    }
    for(int i=0;i<moves.size();i+=4){
        string opt=moves.substr(i,3);
        solve(locate(start),opt[0]=='C',opt[1]=='C',(int)opt[2]);
    }
    int pos=locate(start)[0];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            ans+=f[pos][i][j];
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string start;
    getline(cin, start);

    string moves;
    getline(cin, moves);

    string result = rotateCube(start, moves);

    fout << result << "\n";

    fout.close();

    return 0;
}

