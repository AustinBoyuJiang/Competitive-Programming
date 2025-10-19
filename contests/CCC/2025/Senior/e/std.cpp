#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
// A very small value to represent –infinity.
const ll MINF = -1000000000000000000LL; // -1e18 (sufficiently small)
 
// The modulus used in decryption.
const int MOD = 1000003; // 10^6 + 3
 
// Structure to hold our segment tree node value.
struct Node {
    ll S, C; // f(x) = max(x + S, C)
};
 
// Composition operator: combine left (L) then right (R).
// If L represents f_L(x)=max(x + S_L, C_L)
// and R represents f_R(x)=max(x + S_R, C_R)
// then f_R(f_L(x)) = max( x + S_L + S_R,  max(C_L + S_R, C_R) ).
Node combine(const Node &L, const Node &R) {
    Node res;
    res.S = L.S + R.S;
    res.C = max(L.C + R.S, R.C);
    return res;
}
 
// Make a leaf node corresponding to release time s and total processing time v.
// If v == 0 (no tasks at this release time) we return identity: (0, -INF)
// Otherwise, for tasks with release time s and total processing time v,
// the function is: f(x) = max(x + v, s + v - 1).
Node make_node(int s, ll v) {
    Node res;
    res.S = v;
    if(v > 0)
        res.C = s + v - 1;
    else
        res.C = MINF;
    return res;
}
 
// Global segment tree variables.
int n; // size of base (power of two) covering indices 0..MOD-1
vector<Node> seg; // segment tree array
 
// Our array of accumulated processing times for each release time.
vector<ll> arrVal; // arrVal[s] for s in [0, MOD-1]
 
// Build the segment tree leaves from arrVal.
void build_tree() {
    for (int i = 0; i < MOD; i++){
        seg[n + i] = make_node(i, arrVal[i]);
    }
    for (int i = MOD; i < n; i++){
        // For indices not in [0,MOD-1], set identity.
        seg[n + i] = {0, MINF};
    }
    for (int i = n - 1; i > 0; i--){
        seg[i] = combine(seg[2*i], seg[2*i+1]);
    }
}
 
// Update position pos (0-indexed) in arrVal.
void update_tree(int pos, ll newVal) {
    int idx = n + pos;
    seg[idx] = make_node(pos, newVal);
    for (idx /= 2; idx >= 1; idx /= 2){
        seg[idx] = combine(seg[2*idx], seg[2*idx+1]);
    }
}
 
// Query the whole range. (We only need the overall composition.)
Node query_all() {
    return seg[1];
}
 
// Structure to store an added task.
struct Task {
    int s; // release time (after decryption; 0-indexed)
    int t; // processing time
    bool active;
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int Q;
    cin >> Q;
 
    // Our segment tree covers indices 0 .. MOD-1.
    // Set n to be the smallest power of 2 >= MOD.
    n = 1;
    while(n < MOD) n *= 2;
    seg.assign(2*n, {0, MINF});
    arrVal.assign(MOD, 0);
 
    // We'll store tasks (assignment id) in a vector.
    // Since Q can be up to 1e6, we preallocate.
    vector<Task> tasks;
    tasks.resize(Q+1); // 1-indexed assignment id.
    int addCount = 0;  // counts number of add operations
     
    // Initially, there are no tasks. (But the problem guarantees at least one task after every update.)
    // We will update the tree as tasks are added.
    build_tree();
 
    ll ans = 0; // answer from previous update (initially 0)
 
    for (int qi = 0; qi < Q; qi++){
        char type;
        cin >> type;
        if(type == 'A'){
            int s_enc, t_enc;
            cin >> s_enc >> t_enc;
            // Decrypt using ans (from previous update)
            int s = (s_enc + ans) % MOD;  // s in [0, MOD-1]
            int t = (t_enc + ans) % MOD;  // t in [0, MOD-1]
            // (It is guaranteed that after decryption each added task is valid.)
 
            // Record this task with a new assignment id.
            addCount++;
            tasks[addCount] = {s, t, true};
 
            // Update the aggregated value for release time s.
            arrVal[s] += t;
            update_tree(s, arrVal[s]);
 
        } else if(type == 'D'){
            int i_enc;
            cin >> i_enc;
            // Decrypt the assignment id to remove.
            int id = (i_enc + ans) % MOD;  // id is taken modulo MOD.
            // In the unencrypted sample, for example, D 999991 with ans=13 gives id = 1.
            // According to the problem statement, the assignment number is the one in which it was added.
            // (It is guaranteed that the assignment with that id exists and is active.)
            if(id >= 1 && id <= addCount && tasks[id].active) {
                tasks[id].active = false;
                int s = tasks[id].s;
                int t = tasks[id].t;
                arrVal[s] -= t;
                update_tree(s, arrVal[s]);
            }
        }
 
        // Query the overall segment tree to compute the composition over all release times.
        Node total = query_all();
        // The optimal finishing time is F(0) = max(0 + total.S, total.C).
        ll cur_ans = max(total.S, total.C);
        cout << cur_ans << "\n";
        ans = cur_ans; // update ans for decryption in subsequent queries
    }
 
    return 0;
}

