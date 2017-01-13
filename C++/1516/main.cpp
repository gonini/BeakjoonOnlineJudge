#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define MAX 501
using namespace std;

vector<int> a[MAX];
int cost[MAX];
int ind[MAX];
int d[MAX];

int main(void){
    memset(ind, 0, sizeof(ind));
    memset(cost, 0, sizeof(cost));
    memset(d, 0, sizeof(d));

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &cost[i]);
        while (true) {
            int u;
            scanf("%d", &u);
            if(u == -1) {
                break;
            }
            a[u].push_back(i);
            ind[i] += 1;
        }
    }
    
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(ind[i] == 0) {
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
    
    for(int i = 1; i <= n; i++) {
        printf("%d\n", d[i]);
    }
}
