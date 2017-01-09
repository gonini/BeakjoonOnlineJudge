#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define MAX  1003

using namespace std;

vector<int> a[MAX];
bool isVisit[MAX];

bool dfs(int v);

int main(void){
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            int v;
            scanf("%d", &v);
            a[i].push_back(v);
            a[v].push_back(i);
        }
        int ret = 0;
        for(int i = 1; i <= n; i++) {
            if (dfs(i)) {
                ret += 1;
            }
        }
        printf("%d\n", ret);
        
        memset(isVisit, false, sizeof(isVisit));
        for(int i = 0; i <= n; i++) {
            a[i].clear();
        }
    }
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
