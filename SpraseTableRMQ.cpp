#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, j, k) for(int i = j; i < k; i++)
const ll maxN = 2e5 + 5;

/// Replace min for other ops
long long sparseTable[maxN][31];
int LOG[maxN];
void fillLog() {
    LOG[1] = 0;
    for(int i = 2; i < maxN; i++) {
        LOG[i] = LOG[i / 2] + 1;
    }       
}    

void fillSpraseTable(long long *arr, int n) {
    fillLog();
    for(int i = 0; i < n; i++) {
        sparseTable[i][0] = arr[i];
    }
    for(int j = 1; j < 31; j++) {
        for(int i = 0; i + (1 << j) <= n; i++) {
            sparseTable[i][j] = min(sparseTable[i][j-1], sparseTable[i + (1 << (j - 1))][j - 1]);
        }
    }
}

long long query(int l, int r) {
    int j = LOG[r - l + 1];
    return min(sparseTable[l][j], sparseTable[r - (1 << j) + 1][j]);
}
