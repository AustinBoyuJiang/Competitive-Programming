#include <bits/stdc++.h>
using namespace std;

struct segment{
	int id,l,r,len;
}; 
/*============================  ���ݽṹ  ============================*/
class SegmentListIdx {
    /* ---------- ���ڵ� ---------- */
    struct Node {
        segment seg;        // ��Ŀ����������
        int pr;             // ������ȼ�
        int sz;             // ������С
        int ch[2];          // ch[0] = �����, ch[1] = �Ҷ���
        int parent;         // ���ڵ���������Ϊ -1
        Node(const segment& s, int _pr)
            : seg(s), pr(_pr), sz(1), parent(-1) { ch[0] = ch[1] = -1; }
    };

    vector<Node> pool;      // �洢���нڵ�
    int root = -1;          // ��������������
    unordered_map<int,int> posOfId;   // id �� �ڵ�����

    /* ---------- �ڲ�С���� ---------- */
    int sz(int x)     const { return x == -1 ? 0 : pool[x].sz; }
    void pull(int x) {
        if (x == -1) return;
        for (int d : {0,1})
            if (pool[x].ch[d] != -1)
                pool[ pool[x].ch[d] ].parent = x;
        pool[x].sz = 1 + sz(pool[x].ch[0]) + sz(pool[x].ch[1]);
    }

    void split(int v, int k, int& a, int& b) {      // ǰ k �� �� a
        if (v == -1) { a = b = -1; return; }
        if (sz(pool[v].ch[0]) >= k) {               // �������
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

    int kthIdx(int v, int k) const {                // ������ k �Ľڵ�����
        while (v != -1) {
            int lsz = sz(pool[v].ch[0]);
            if (k < lsz)           v = pool[v].ch[0];
            else if (k == lsz)     return v;
            else { k -= lsz + 1;   v = pool[v].ch[1]; }
        }
        return -1;
    }

    int rankOfNode(int x) const {                   // �ڵ����� �� ����
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
    /* ---------- �� id �� λ�� ---------- */
    int positionOfId(int id) const {
        auto it = posOfId.find(id);
        return it == posOfId.end() ? -1 : rankOfNode(it->second);
    }

    /* ---------- �� �� pos ������ ---------- */
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

    /* ---------- �� �� id ɾ�� ---------- */
    bool removeId(int id) {
        auto it = posOfId.find(id);
        if (it == posOfId.end()) return false;
        int idx = it->second;
        int pos = rankOfNode(idx);
        int a,b,c; split(root, pos, a, b);
        split(b, 1, b, c);              // b ֻ��Ŀ��ڵ�
        root = merge(a, c);
        if (root != -1) pool[root].parent = -1;
        posOfId.erase(it);
        return true;
    }

    /* ---------- �� ���� ---------- */
    template<class F> void traverse(F fn) const { dfs(root, fn); }

    /* ---------- �� id �� segment* ---------- */
    const segment* getSegmentById(int id) const {
        auto it = posOfId.find(id);
        return it == posOfId.end() ? nullptr : &pool[it->second].seg;
    }

    /* ---------- �� pos �� segment* ---------- */
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

/*============================  ��ʾ ============================*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(123456);                 // �̶�������ӣ����㸴�֣�

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

