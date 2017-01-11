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
    
    queue<int> q;
    for(int i = 1 ; i <= n; i++) {
        if(!ind[i]) {
            q.push(i);
        }
    }
    
    for(int i = 0; i < n; i++) {
        int x = q.front();
        q.pop();
        printf("%d ", x);
        
        for(int i = 0; i < a[x].size(); i++) {
            int there = a[x][i];
            ind[there] -= 1;
            if (!ind[there]) {
                q.push(there);
            }
        }
    }
}
