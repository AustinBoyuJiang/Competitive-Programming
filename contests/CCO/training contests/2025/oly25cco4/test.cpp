#include <bits/stdc++.h>
using namespace std;

struct segment{
	int id,l,r,len;
}; 
/*============================  数据结构  ============================*/
class SegmentListIdx {
    /* ---------- 树节点 ---------- */
    struct Node {
        segment seg;        // 题目给定的数据
        int pr;             // 随机优先级
        int sz;             // 子树大小
        int ch[2];          // ch[0] = 左儿子, ch[1] = 右儿子
        int parent;         // 父节点索引，根为 -1
        Node(const segment& s, int _pr)
            : seg(s), pr(_pr), sz(1), parent(-1) { ch[0] = ch[1] = -1; }
    };

    vector<Node> pool;      // 存储所有节点
    int root = -1;          // 整棵树根的索引
    unordered_map<int,int> posOfId;   // id → 节点索引

    /* ---------- 内部小工具 ---------- */
    int sz(int x)     const { return x == -1 ? 0 : pool[x].sz; }
    void pull(int x) {
        if (x == -1) return;
        for (int d : {0,1})
            if (pool[x].ch[d] != -1)
                pool[ pool[x].ch[d] ].parent = x;
        pool[x].sz = 1 + sz(pool[x].ch[0]) + sz(pool[x].ch[1]);
    }

    void split(int v, int k, int& a, int& b) {      // 前 k 个 → a
        if (v == -1) { a = b = -1; return; }
        if (sz(pool[v].ch[0]) >= k) {               // 都在左边
            split(pool[v].ch[0], k, a, pool[v].ch[0]);
            b = v;
        } else {
            split(pool[v].ch[1], k - sz(pool[v].ch[0]) - 1,
                  pool[v].ch[1], b);
            a = v;
        }
        pool[v].parent = -1;
        pull(v);
    }

    int merge(int a, int b) {
        if (a == -1 || b == -1) return a == -1 ? b : a;
        if (pool[a].pr < pool[b].pr) {
            pool[a].ch[1] = merge(pool[a].ch[1], b);
            pull(a);
            return a;
        } else {
            pool[b].ch[0] = merge(a, pool[b].ch[0]);
            pull(b);
            return b;
        }
    }

    int kthIdx(int v, int k) const {                // 找排名 k 的节点索引
        while (v != -1) {
            int lsz = sz(pool[v].ch[0]);
            if (k < lsz)           v = pool[v].ch[0];
            else if (k == lsz)     return v;
            else { k -= lsz + 1;   v = pool[v].ch[1]; }
        }
        return -1;
    }

    int rankOfNode(int x) const {                   // 节点索引 → 排名
        int res = sz(pool[x].ch[0]);
        while (pool[x].parent != -1) {
            int p = pool[x].parent;
            if (pool[p].ch[1] == x)
                res += 1 + sz(pool[p].ch[0]);
            x = p;
        }
        return res;
    }

public:
    /* ---------- ① id → 位置 ---------- */
    int positionOfId(int id) const {
        auto it = posOfId.find(id);
        return it == posOfId.end() ? -1 : rankOfNode(it->second);
    }

    /* ---------- ② 在 pos 处插入 ---------- */
    bool insertAt(int pos, const segment& s) {
        if (pos < 0 || pos > sz(root) || posOfId.count(s.id)) return false;
        int a,b; split(root, pos, a, b);
        int idx = (int)pool.size();
        pool.emplace_back(s, rand());
        posOfId[s.id] = idx;
        root = merge( merge(a, idx), b );
        pool[root].parent = -1;
        return true;
    }

    /* ---------- ③ 按 id 删除 ---------- */
    bool removeId(int id) {
        auto it = posOfId.find(id);
        if (it == posOfId.end()) return false;
        int idx = it->second;
        int pos = rankOfNode(idx);
        int a,b,c; split(root, pos, a, b);
        split(b, 1, b, c);              // b 只有目标节点
        root = merge(a, c);
        if (root != -1) pool[root].parent = -1;
        posOfId.erase(it);
        return true;
    }

    /* ---------- ④ 遍历 ---------- */
    template<class F> void traverse(F fn) const { dfs(root, fn); }

    /* ---------- ⑤ id → segment* ---------- */
    const segment* getSegmentById(int id) const {
        auto it = posOfId.find(id);
        return it == posOfId.end() ? nullptr : &pool[it->second].seg;
    }

    /* ---------- ⑥ pos → segment* ---------- */
    const segment* getSegmentByPos(int pos) const {
        if (pos < 0 || pos >= sz(root)) return nullptr;
        return &pool[ kthIdx(root, pos) ].seg;
    }

private:
    template<class F> void dfs(int v, F fn) const {
        if (v == -1) return;
        dfs(pool[v].ch[0], fn);
        fn(pool[v].seg);
        dfs(pool[v].ch[1], fn);
    }
};

/*============================  演示 ============================*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(123456);                 // 固定随机种子（方便复现）

    SegmentListIdx ds;
    ds.insertAt(0, {1,0,10,11});
    ds.insertAt(1, {2,11,20,10});
    ds.insertAt(2, {3,21,30,10});

    cout << "pos(id=2) = " << ds.positionOfId(2) << '\n';  // 1

    ds.removeId(2);
    ds.insertAt(1, {4,100,200,101});

    cout << "current order:\n";
    ds.traverse([](const segment& s){
        cout << "id=" << s.id
             << " [" << s.l << ',' << s.r << "] "
             << "len=" << s.len << '\n';
    });

    if (auto* p = ds.getSegmentByPos(1))
        cout << "\npos=1  ?  id=" << p->id << " len=" << p->len << '\n';
}

