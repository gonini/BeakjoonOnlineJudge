#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define MAX 100003

using namespace std;

int a[MAX];
int s[MAX];
int d[MAX];
int n;

int dfs(int x, int cnt, int step);

int main(void){
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for(int v = 1; v <= n; v++) {
            scanf("%d", &a[v]);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if (d[i] == 0) {
                cnt += dfs(i, 1, i);
            }
        }
        memset(a, 0, sizeof(a));
        memset(s, 0, sizeof(s));
        memset(d, 0, sizeof(d));
        printf("%d\n", n - cnt);
    }
}

int dfs(int x, int cnt, int step) {
    if (d[x] != 0) {
        if (step != s[x]) {
            return 0;
        }
        return cnt - d[x];
    }
    
    d[x] = cnt;
    s[x] = step;
    return dfs(a[x], cnt + 1, step);
}

