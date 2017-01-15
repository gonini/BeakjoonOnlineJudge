#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define MAX 1001
using namespace std;

int a[MAX][3];
int d[MAX][3];

int rgb(int n, int idx);

int main(void) {
    memset(a, 0, sizeof(a));
    memset(d, -1, sizeof(d));
    
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    int ans = ~(1<<31);
    for(int i = 0; i < 3; i++) {
        ans = min(ans, rgb(n-1, i));
    }
    
    printf("%d\n", ans);
}

int rgb(int n, int idx) {
    if(n < 0) {
        return 0;
    }
    
    if (idx < 0) {
        idx = 2;
    }
    if (idx > 2) {
        idx = 0;
    }
    
    int& cache = d[n][idx];
    
    if(n == 0) {
        return cache = a[0][idx];
    }
    if(cache > -1) {
        return cache;
    }
    return cache = a[n][idx] + min(rgb(n-1, idx-1), rgb(n-1, idx+1));
}
