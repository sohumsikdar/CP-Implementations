# CP_Implementations
Implementations of Common Data Structures and Algorithms for CP
<br><br>
## DSU
    Disjoint set implemented using both path compression and Union by Rank/size
    O(α(n)) queries. α(n) = 4 for all n < 1e600

## Shortest Paths
    1) Dijktra: Standard SSSP implmentaion using STL set. O(Elog(V) + Vlog(E)) 
    2) Bellman Ford: Another SSSP but works for neg edges and detects Neg Cycles
    3) Floyd Warshal: All source shortest path, cubic time.

## Binary Lifting / LCA
    LCA queries in a rooted tree in O(log(n)) time with O(nlog(n)) pre-processing

## kahn
    Topological sort runs on O(V + E)

## Kruskal
    Implement a DSU, returns the MST Weight and MST in O(ElogE) time