#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define MAX 20003
#define RED 0
#define BLUE 1

using namespace std;

vector<int> a[MAX];
int color[MAX];

bool dfs(int v, int preColor);

int main(void){
    int k;
    scanf("%d", &k);
    while (k--) {
        int V, E;
        scanf("%d %d", &V, &E);
        for(int i = 0; i < E; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        
        memset(color, -1, sizeof(color));
        
        bool check = false;
        for(int i = 1; i <= V; i++) {
            if (color[i] < 0 && !dfs(i, RED)) {
                check = true;
            }
        }
        
        if (!check) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        
        for(int i = 0; i < MAX; i++) {
            a[i].clear();
        }
    }
}

bool dfs(int v, int preColor) {
    int &curColor = color[v];
    if (curColor > -1) {
        return curColor != preColor;
    }
    curColor = (preColor == RED ? BLUE : RED);
    for(int i = 0; i < a[v].size(); i++) {
        if (!dfs(a[v][i], curColor)) {
            return false;
        }
    }
    return true;
}

