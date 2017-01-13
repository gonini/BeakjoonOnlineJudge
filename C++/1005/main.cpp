#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define MAX 1001
using namespace std;

vector<int> a[MAX];
int cost[MAX];
int ind[MAX];
int d[MAX];

void solve();

int main(void){
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(ind, 0, sizeof(ind));
        memset(cost, 0, sizeof(cost));
        memset(d, 0, sizeof(d));
        solve();
        for(int i = 1; i < MAX; i++) {
            a[i].clear();
        }
    }
}

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &cost[i]);
    }
    
    for(int i = 0; i < k; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        ind[v] += 1;
    }
    
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            q.push(i);
            d[i] = cost[i];
        }
    }
    
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        for(int i = 0; i < a[here].size(); i++) {
            int there = a[here][i];
            
            if (d[there] < d[here] + cost[there]) {
                d[there] = d[here] + cost[there];
            }
            ind[there] -= 1;
            if (ind[there] == 0) {
                q.push(there);
            }
        }
    }
    int w;
    scanf("%d", &w);
    printf("%d\n", d[w]);

}
