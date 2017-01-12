#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define MAX 10001
using namespace std;

int cost[MAX];
int ind[MAX];
int d[MAX];
vector<int> a[MAX];


int main(void){
    
    memset(ind, 0, sizeof(ind));
    memset(d, 0, sizeof(d));
    
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &cost[i]);
        
        int c;
        scanf("%d", &c);
        for(int j = 0; j < c; j++) {
            int u;
            scanf("%d", &u);
            a[i].push_back(u);
            ind[u] += 1;
        }
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
            ind[there] -= 1;
            
            if (d[there] < d[here] + cost[there]) {
                d[there] = d[here] + cost[there];
            }
            
            if (ind[there] == 0) {
                q.push(there);
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, d[i]);
    }
    
    printf("%d\n", ans);
}
