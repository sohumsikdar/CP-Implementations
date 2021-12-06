#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
    ll a, b, weight;
};

bool cmp(edge& a, edge& b){
    return a.weight < b.weight;
}

pair<ll, vector<pair<ll, ll>>> kruskal(vector<edge>& eList, int n) {
    sort(eList.begin(), eList.end(), cmp);
    // DSU u(n); define DSU
    vector<pair<ll, ll>> mst;
    ll mstWeight = 0;

    for(auto e: eList) {
        if(u.find(e.a) != u.find(e.b)) {
            u.merge(e.a, e.b);
            mst.push_back({e.a, e.b});
            mstWeight += e.weight;
        }
    }

    return {mstWeight, mst};
}