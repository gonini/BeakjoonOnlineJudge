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

void dfs(int v);
void bfs(int v);

int main(void){
    int n, m, start;
    scanf("%d %d %d", &n, &m, &start);
    
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    for(int i = 1; i <= n; i++) {
        sort(a[i].begin(), a[i].end());
    }
    
    memset(isVisit, false, sizeof(isVisit));
    dfs(start);
    printf("\n");
    memset(isVisit, false, sizeof(isVisit));
    bfs(start);
    
}

void dfs(int v) {
    isVisit[v] = true;
    printf("%d ", v);
    for(int i = 0; i < a[v].size(); i++) {
        if (!isVisit[a[v][i]]) {
            dfs(a[v][i]);
        }
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    isVisit[v] = true;

    while(!q.empty()) {
        int here = q.front();
        q.pop();
        printf("%d ", here);
        for(int i = 0; i < a[here].size(); i++) {
            int there = a[here][i];
            if(!isVisit[there]) {
                isVisit[there] = true;
                q.push(there);
                
            }
        }
    }
}
