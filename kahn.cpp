#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

bool kahn(vector<vl>& g, vector<bool>& vis, vl& inDeg, vl& topSorted){
    queue <ll> bfsQ;
    for(int i = 1; i < g.size(); i++){
        if(inDeg[i] == 0){
            bfsQ.push(i);
        }
    }
    
    while(!bfsQ.empty()){
        ll cur = bfsQ.front();
        topSorted.push_back(cur);
        bfsQ.pop();

        for(auto i: g[cur]){
            inDeg[i]--;
            if(inDeg[i] == 0) bfsQ.push(i);
        }
    }

    return topSorted.size() == g.size() - 1;
}

