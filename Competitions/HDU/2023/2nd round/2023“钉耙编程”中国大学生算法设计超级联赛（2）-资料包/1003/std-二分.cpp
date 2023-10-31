#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 2e5 + 5, N2 = 2 * N, N4 = 4 * N;
int n, m, k, a[N];
int ver[N], h; // 需要建立建虚树的询问点
bool isQry[N]; // 是询问点
bool deleted[N]; // 是被删除的点
struct P {
    int x, y;
} b[N]; // 存放输入的边

struct edge { // 链式前向星存3张图，用数组表示
    int to, nx;
} e[3][N4];
int hd[3][N2], tot[3];

void add(int i, int x, int y) { // 在下标i的图上加边，i=0:删掉部分点后的原图 i=1:圆方树 i=2:虚树
    e[i][++tot[i]] = {y, hd[i][x]};
    hd[i][x] = tot[i];
}

int low[N], dfn[N]; // rt=tarjan的dfs树的根节点，low=追溯值，dfn=dfs序
int sta[N2], top; // 栈
int vdcc_cnt; // 点双联通分量个数

void tarjan(int x) {
    low[x] = dfn[x] = ++dfn[0];
    sta[++top] = x;
    for (int i = hd[0][x]; i; i = e[0][i].nx) {
        int y = e[0][i].to;
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
            if (dfn[x] <= low[y]) {
                ++vdcc_cnt;
                add(1, vdcc_cnt + n, x);
                add(1, x, vdcc_cnt + n);
                int z;
                do {
                    z = sta[top--];
                    add(1, vdcc_cnt + n, z);
                    add(1, z, vdcc_cnt + n);
                } while (z != y);
            }
        }
        else low[x] = min(low[x], dfn[y]);
    }
}

// 树剖
int fa[N2], d[N2], son[N2], tp[N2], sz[N2], dfn1[N2];
bool vis[N2];
int sz1[N2], val[N2]; // sz1=子树val和， 询问点val=1，非询问点val=0
bool flag; // 连通块满足：删除一个点可以使得剩余询问点两两不连通

void dfs1(int x, int f) {
    vis[x] = true;
    d[x] = d[f] + 1;
    fa[x] = f;
    sz[x] = 1;
    son[x] = 0;
    if (x <= n && isQry[x]) {
        ver[++h] = x;
        val[x] = 1;
    }
    for (int i = hd[1][x]; i; i = e[1][i].nx) {
        int y = e[1][i].to;
        if (y == f) continue;
        dfs1(y, x);
        sz[x] += sz[y];
        if (sz[y] > sz[son[x]]) son[x] = y;
    }
}

void dfs2(int x, int t) {
    tp[x] = t;
    dfn1[x] = ++dfn1[0];
    if (son[x]) dfs2(son[x], t);
    for (int i = hd[1][x]; i; i = e[1][i].nx) {
        int y = e[1][i].to;
        if (!dfn1[y]) dfs2(y, y);
    }
}

int lca(int x, int y) {
    while (tp[x] != tp[y]) {
        if (d[tp[x]] < d[tp[y]]) swap(x, y);
        x = fa[tp[x]];
    }
    return d[x] < d[y] ? x : y;
}

int build_virtual_tree(int b[], int h) { // 对b[1~h]建虚树，返回根
    sort(b + 1, b + 1 + h, [](int i, int j) {
        return dfn1[i] < dfn1[j];
    });
    sta[top = 1] = b[1];
    for (int i = 2; i <= h; ++i) {
        int ff = lca(b[i], sta[top]);
        while (true) {
            if (d[ff] >= d[sta[top - 1]]) {
                if (ff != sta[top]) {
                    add(2, ff, sta[top]);
                    if (ff != sta[top - 1]) sta[top] = ff;
                    else --top;
                }
                break;
            }
            else {
                add(2, sta[top - 1], sta[top]);
                --top;
            }
        }
        sta[++top] = b[i];
    }
    while (--top) add(2, sta[top], sta[top + 1]);
    return sta[1]; //
}

void dfs3(int x, int f) {
    ll sum = 0; // 询问点之间的路径，经过x点的路径数的2倍，即(u->v)和(v->u)算两条
    if (val[x]) sum = h - 1; // u=x的
    sz1[x] = val[x];
    for (int i = hd[2][x]; i; i = e[2][i].nx) {
        int y = e[2][i].to;
        if (y == f) continue;
        dfs3(y, x);
        sz1[x] += sz1[y];
        sum += 1ll * sz1[y] * (h - sz1[y]); // u=子树y中的点，v=非子树y中的点
    }
    sum += 1ll * sz1[x] * (h - sz1[x]); // u=非子树x中点，v=子树x中的点
    if (sum == 1ll * h * (h - 1) && x <= n) flag = true; // 经过x的路径数=h*(h-1)/2，且x是圆点
}

void del(int x, int f) { // 删除虚树的边
    for (int i = hd[2][x]; i; i = e[2][i].nx) {
        int y = e[2][i].to;
        if (y == f) continue;
        del(y, x);
    }
    hd[2][x] = 0;
}

void init() {
    memset(dfn + 1, 0, n << 2);
    memset(low + 1, 0, n << 2);
    memset(vis + 1, 0, n << 1);
    memset(dfn1 + 1, 0, n << 3);
    memset(val + 1, 0, n << 2);
    memset(deleted + 1, 0, n);
    dfn[0] = dfn1[0] = 0;
    memset(hd[0] + 1, 0, n << 2);
    memset(hd[1] + 1, 0, n << 3);
    tot[0] = tot[1] = 0;
    vdcc_cnt = 0;
    top = 0;
}

bool check(int mid) {
    init();
    for (int i = 1; i <= mid; ++i) deleted[a[i]] = true;
    for (int i = 1; i <= m; ++i) { // 删除a[1~mid]后的图
        int x = b[i].x, y = b[i].y;
        if (deleted[x] || deleted[y]) continue;
        add(0, x, y);
        add(0, y, x);
    }
    for (int i = 1; i <= n; ++i) { // 删除a[1~mid]后的图建圆方树森林
        if (deleted[i]) continue;
        if (!dfn[i]) tarjan(i);
    }
    bool valid = true; // 存在无法通过删除一个点来两两切断的连通块
    int cnt = 0; // 需要删掉一个点的联通分量个数
    for (int i = 1; i <= n; ++i) {
        if (deleted[i] || vis[i]) continue;
        h = 0;
        dfs1(i, 0);
        if (h <= 1) continue; // 只有1个点不需要考虑，至少2个点时需要判断能否删掉一个点来满足要求
        dfs2(i, i);
        int root = build_virtual_tree(ver, h); // 询问点建虚树
        flag = false; // 联通块满足条件
        dfs3(root, 0); // 虚数上dfs
        del(root, 0);  // 删除虚树
        tot[2] = 0;    // 删除虚树
        if (flag) {
            ++cnt;
            if (cnt >= 2) break;
        }
        else {
            valid = false;
            break;
        }
    }
    return valid && cnt <= 1;
}

void work() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        cin >> b[i].x >> b[i].y;
    }
    memset(isQry + 1, 0, n);
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
        isQry[a[i]] = true;
    }
    if (k <= 2) {
        cout << "0\n";
        return;
    }
    int l = 0, r = k - 2, ans = -1; // 答案必然在[0,k-2]范围，因为最后两个点删掉一个必然满足要求
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid, r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
//    assert(ans != -1);
    cout << ans << "\n";
}

int main() {
//    freopen("CS.in", "r", stdin);
//    freopen("CS1.out", "w", stdout);
//    long long A = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        work();
    }
//    cerr << "std(nlog^2n)time=" << clock() - A;
}