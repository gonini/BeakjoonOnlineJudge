#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define MAX 1001
using namespace std;

vector<pair<int, int>> a[MAX];
bool isVisit[MAX];

int main(void){
    memset(isVisit, false, sizeof(isVisit));
    
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        a[u].push_back(make_pair(v, c));
        a[v].push_back(make_pair(u, c));
    }
    
    priority_queue<pair<int, int>> q;
    
    isVisit[1] = true;
    for(int i = 0; i < a[1].size(); i++) {
        auto t = a[1][i];
        int there = t.first;
        int cost = t.second;
        q.push(make_pair(-cost, there));
    }
    
    int ans = 0;
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        int cost = -t.first;
        int there = t.second;
        
        if (isVisit[there]) {
            continue;
        }
        isVisit[there] = true;
        ans += cost;
        for(int i = 0; i < a[there].size(); i++) {
            auto t1 = a[there][i];
            q.push(make_pair(-t1.second, t1.first));
        }
    }
    printf("%d", ans);
}
