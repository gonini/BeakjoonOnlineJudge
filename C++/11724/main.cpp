#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define MAX 1003

using namespace std;

vector<int> a[MAX];
bool isVisit[MAX];

bool dfs(int v);

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
 
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    memset(isVisit, false, sizeof(isVisit));
    
    int ret = 0;
    for(int i = 1; i <= n; i++) {
        if (dfs(i)) {
            ret += 1;
        }
    }
    
    printf("%d\n", ret);
}

bool dfs(int v) {
    if (isVisit[v]) {
        return false;
    }
    isVisit[v] = true;
    for(int i = 0; i < a[v].size(); i++) {
        int there = a[v][i];
        dfs(there);
    }
    return true;
}
