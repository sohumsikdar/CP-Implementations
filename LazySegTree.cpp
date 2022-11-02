template<typename T>
class SegTreeLazy {
    int left(int v) {return 2 * v;}
    int right(int v) {return 2*v + 1;}
    
    public:
    int n;
    vector<T> Tree, Lazy;

    SegTreeLazy(vector<T>& arr) {
        n = arr.size();
        Tree.assign(4 * n + 1, 0);
        Lazy.assign(4 * n + 1, 0);
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
        Tree[v] = Tree[left(v)] + Tree[right(v)];
    }   

    T query(int l, int r) { return query(1, l, r, 0, n - 1); }

    T query(int v, int l, int r, int tl, int tr) {
        lazy_prop(v, tl, tr, Lazy[v]);
        Lazy[v] = 0;
        if(l > tr || r < tl) return 0;
        if(l <= tl && r >= tr) return Tree[v];
        int tm = (tl + tr) / 2;
        T leftQuery = query(left(v), l, r, tl, tm);
        T rightQuery = query(right(v), l, r, tm + 1, tr);
        return leftQuery + rightQuery;
    }

    void update_range(int l, int r, T val) { update_range(1, l, r, 0, n - 1, val); }

    void update_range(int v, int l, int r, int tl, int tr, T val) {
        lazy_prop(v, tl, tr, Lazy[v]);
        Lazy[v] = 0;

        if(l > tr || r < tl) return;
        if(l <= tl && r >= tr) {
            lazy_prop(v, tl, tr, val);
            return;
        }

        int tm = (tl + tr) / 2;
        update_range(left(v), l, r, tl, tm, val);
        update_range(right(v), l, r, tm + 1, tr, val);
        Tree[v] = Tree[left(v)] + Tree[right(v)];
    }

    void lazy_prop(int v, int l, int r, T val) {
        Tree[v] += val * (r - l + 1);
        if(r != l) {
            Lazy[left(v)] += val;
            Lazy[right(v)] += val;
        }
    }   
};
