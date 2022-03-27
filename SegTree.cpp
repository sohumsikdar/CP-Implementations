template<typename T>
class SegTree {
    int left(int v) {return 2 * v;}
    int right(int v) {return 2*v + 1;}
    
    public:
    int n;
    vector<T> Tree;
    SegTree(vector<T>& arr) {
        n = arr.size();
        Tree.assign(4 * n + 1, 0);
        build(arr, 1, 0, n - 1);
    }

    void build(vector<T>& arr, int v, int l, int r) {
        if(l == r) {
            Tree[v] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        build(arr, left(v), l, mid);
        build(arr, right(v), mid + 1, r);

        //Merge ---- change from sum to whatever needed
        Tree[v] = Tree[left(v)] + Tree[right(v)];
    }   

    T query(int l, int r) { return query(1, l, r, 0, n - 1); }

    T query(int v, int l, int r, int tl, int tr) {
        // No overlap case
        if(l > tr || r < tl) return 0;
        // Perfect overlap
        if(l <= tl && r >= tr) return Tree[v];

        int tm = (tl + tr) / 2;
        T leftQuery = query(left(v), l, r, tl, tm);
        T rightQuery = query(right(v), l, r, tm + 1, tr);

        //Merge ---- change from sum to whatever needed
        return leftQuery + rightQuery;
    }

    void update(int idx, T val) { update(1, 0, n - 1, idx, val); }

    void update(int v, int l, int r, int idx, T val) {
        if(l == r) {
            Tree[v] = val;
            return;
        }

        int m = l + (r - l) / 2;
        if(idx <= m) update(left(v), l, m, idx, val);
        else update(right(v), m + 1, r, idx, val);

        //Merge ---- change from sum to whatever needed
        Tree[v] = Tree[left(v)] + Tree[right(v)];
    }
};