#include <bits/stdc++.h>
using namespace std;
 
const int M = 25000;
const int N = 50000 * 3;
const int inf = 0x3f3f3f3f;
 
int T, R, P, S;
 
int cnt;
int head[M + 5];
struct node
{
    int v, w, nx;
}Edge[N + 5];
 
int dis[M + 5];
bool vis[M + 5];
 
int in[M + 5];
int tot, block[M + 5];
 
void init()
{
    tot = cnt = 0;
    for(int i = 1; i <= T; ++i)
    {
        vis[i] = 0;
        head[i] = -1;
        dis[i] = inf;
 
        in[i] = 0;
        block[i] = 0;
    }
}
 
void add(int u, int v, int w)
{
    Edge[cnt].v = v;
    Edge[cnt].w = w;
    Edge[cnt].nx = head[u];
    head[u] = cnt++;
}
 
void dfs(int u)
{
    for(int i = head[u]; ~i; i = Edge[i].nx)
    {
        int v = Edge[i].v;
        if(!block[v])
        {
            block[v] = tot;
            dfs(v);
        }
    }
}
 
queue <int> topo_q;
priority_queue < pair<int, int> > dij_q;
 
void dijkstra(int s)
{
    for(int i = 1; i <= T; ++i)
    {
        if(block[i] == s)   dij_q.push(make_pair(-dis[i], i));
    }
    while(!dij_q.empty())
    {
        int u = dij_q.top().second;
        dij_q.pop();
        if(vis[u])  continue;
        vis[u] = 1;
        for(int i = head[u]; ~i; i = Edge[i].nx)
        {
            int v = Edge[i].v;
            if(dis[v] > dis[u] + Edge[i].w)
            {
                dis[v] = dis[u] + Edge[i].w;
                if(block[v] == s)   dij_q.push(make_pair(-dis[v], v));
            }
            if(block[v] != s && !--in[block[v]])    topo_q.push(block[v]);
        }
    }
}
 
void topo_sort()
{
    for(int i = 1; i <= tot; ++i)
    {
        if(!in[i])  topo_q.push(i);
    }
    while(!topo_q.empty())
    {
        int u = topo_q.front();
        topo_q.pop();
        dijkstra(u);
    }
}
 
int main()
{
    scanf("%d %d %d %d", &T, &R, &P, &S);
    init();
    for(int i = 1, u, v, w; i <= R; ++i)
    {
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w), add(v, u, w);
    }
    for(int i = 1; i <= T; ++i)
    {
        if(!block[i])
        {
            block[i] = ++tot;
            dfs(i);
        }
    }
    for(int i = 1, u, v, w; i <= P; ++i)
    {
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
        ++in[block[v]];
    }
    dis[S] = 0;
    topo_sort();
    for(int i = 1; i <= T; ++i)
    {
        if(dis[i] > 1e9)    printf("NO PATH\n");
        else                printf("%d\n", dis[i]);
    }
    return 0;
}
