#include<bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pl;
const long long inf = 1e18;
const long long ninf = -1e18;

//For bellman ford
struct edge {
    long long a, b, w;
};


//Remember to initialise dist to n + 1, inf
void dijkstra(vector<vector<pl>>& graph, vector<long long, long long>& dist) {
    dist[1] = 0;
    set<pl> pq;
    pq.insert({0, 1});
    while(!pq.empty()) {
        long long src = pq.begin() -> first;
        long long d = pq.begin() -> second;
        pq.erase(pq.begin());

        if(dist[src] < d) continue;
        for(auto to: graph[src]) {
            long long v = to.first; long long c = to.second;
            if(dist[v] > c + d) {
                dist[v] = c + d;
                pq.insert({dist[v], v});
            }
        }
    }
}


void BellmanFord(long long n, vector<edge>& graph){ 
    vector<long long> dist (n + 1, inf);
    dist[1] = 0;

    for(int i = 1; i < n; i++){
        for(auto e: graph){
            if(dist[e.a] == inf) continue;
            if(dist[e.a] + e.w < dist[e.b]){
                dist[e.b] = min(dist[e.b], dist[e.a] + e.w);
                dist[e.b] = max(dist[e.b], ninf);
            }
        }
    }

    //Comment if no neg cycles else dist[n] will become ninf
    for(int i = 1; i < n; i++){
        for(auto e: graph){
            if(dist[e.a] == inf) continue;
            dist[e.b] = max(dist[e.b], ninf);
            if(dist[e.a] + e.w < dist[e.b]){
                dist[e.b] = ninf;
            }
        }
    }
}


//Remember to take input as an adj matrix initialised with inf 
//minimize edge weights while taking input incase of multiple edges
void floydWarshall(vector<vector<long long>>& graph, long long n, long long m){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) graph[i][i] = 0;
                if(graph[i][k] + graph[k][j] < graph[i][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    
    //graph[a][b] will store the shortest path between a and b and will be inf incase no path
}


