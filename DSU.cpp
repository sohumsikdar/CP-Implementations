#include<bits/stdc++.h>
using namespace std;

class DSU {
    public:
    long long nodes;
    long long connectedComp;
    vector<long long> parent;
    vector<long long> size;

    DSU(long long n) {
        nodes = n;
        connectedComp = n;
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        make_set();
    }

    void make_set() {
        for(int i = 1; i <= nodes; i++) {
            parent[i] = i;
        }
    }

    long long find(long long v) {
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    void merge(long long v, long long u) {
        v = find(v);
        u = find(u);
        if(v != u) {
            if(size[v] < size[u]) swap(v, u);
            parent[u] = v;
            size[v] += size[u];
            connectedComp--;
        } 
    }

    long long setSize(long long v) {
        v = find(v);
        return size[v];
    }
};