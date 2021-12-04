#include<bits/stdc++.h>
using namespace std;
typedef vector<long long> vl;
//From main only call fillSparse, Which will initialise the binary lifting sparse table in nlogn time


void dfsParent(long long node, long long parent, vector<vl>& bLift, vector<vl>& tree, vl& lev){
    bLift[node][0] = parent;
    for(auto child: tree[node]){
        if(child != parent){
            lev[child] = lev[node] + 1;
            dfsParent(child, node, bLift, tree, lev);
        }
    }
}


// Make bLift of size n + 1, m = 25 (for n < 1e6) nLogn pre-process
void fillSparse(vector<vl>& bLift, long long n, long long m, vector<vl>& tree, vl& lev){
    lev[1] = 0;
    dfsParent(1, -1, bLift, tree, lev);
    //could hard code m to 26 for n < 1e6
    for(int j = 1; j <= m; j++){
        for(int i = 1; i <= n; i++){
            if(bLift[i][j - 1] != -1){
                long long par = bLift[i][j - 1];
                bLift[i][j] = bLift[par][j - 1];
            }
        }
    }
}

//logn LCA Queries
long long getLCA(vector<vl>& bLift, long long a, long long b, vl& lev){
    if(lev[a] > lev[b]) swap(a, b);
    long long dif = lev[b] - lev[a];
    
    while(dif > 0){
        long long i = log2(dif);
        b = bLift[b][i];
        dif -= (1 << i);
    }
             
    if(a == b) return a;
    long long mx = bLift[0].size();
    
    for(int i = mx - 1; i >= 0; i--){
        if(bLift[a][i] != -1 && (bLift[a][i] != bLift[b][i])) {
            a = bLift[a][i];
            b = bLift[b][i];
        }
    }

    return bLift[a][0];  
}