#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define MAX 32001
using namespace std;

vector<int> a[MAX];
int ind[MAX];

int main(void){
    memset(ind, 0, sizeof(ind));
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        ind[v] += 1;
    }
    
    
    priority_queue<int> pq;
    for(int i = 1 ; i <= n; i++) {
        if(!ind[i]) {
            pq.push(-i);
        }
    }
    
    for(int i = 0; i < n; i++) {
        int x = abs(pq.top());
        pq.pop();
        
        printf("%d ",x);
        
        
        for(int i = 0; i < a[x].size(); i++) {
            int there = a[x][i];
            ind[there] -= 1;
            if (!ind[there]) {
                pq.push(-there);
            }
        }
    }
}
