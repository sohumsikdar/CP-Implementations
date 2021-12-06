#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//Set all for V + 1 size
vector<vector<ll>> g;
vector<bool> vis;
vector<ll> in;
vector<ll> out;
set<ll> cutVertex;
int timer;

void findBridge(ll node, ll parent){
    vis[node] = true;
    low[node] = in[node] = time;
    time++;
    for(auto i : g[node]){
        if(i == parent) continue;

        if(vis[i]){
            low[node] = min(in[i], low[node]);
        }
        else{
            findBridge(i, node);
            low[node] = min(low[node], low[i]);
            if(low[i] > in[node]){
                cout << node << " " << i << " is a bridge\n";
            }
        }
    }
}   

void getCutVert(ll node, ll parent){
    vis[node] = true;
    in[node] = low[node] = timer++;
    ll children = 0;
    for(auto i: g[node]){
        if(i == parent) continue;
        if(vis[i]){
            //back edge
            low[node] = min(in[i], low[node]);
        }
        else{
            //tree edge
            getCutVert(i, node);
            low[node] = min(low[i], low[node]);
            if(low[i] >= in[node] && parent != -1){
                cutVert.insert(node);
            }
            children++;
        }
    }

    if(parent == -1 && children > 1){
        cutVert.insert(node);
    } 
}


int main() {
    return 0;
}