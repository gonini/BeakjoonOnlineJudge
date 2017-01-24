#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define RANGE_OUT 0LL
#define MAX 101
int board[MAX][MAX];
long long cache[MAX][MAX];
int n;

long long canArrive(int x, int y);

int main(void) {
    memset(cache, -1LL, sizeof(cache));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    
    printf("%lld\n", canArrive(1, 1));
}

long long canArrive(int x, int y) {
    if (x > n || y > n) {
        return RANGE_OUT;
    }
    
    long long &here = cache[x][y];
    if (here != -1LL) {
        return here;
    }
    
    if (x == n && y == n) {
        return here = 1LL;
    }
    
    int jump = board[x][y];
    if(jump == 0) {
        return here = 0LL;
    }
    
    return here = canArrive(x + jump, y) + canArrive(x, y + jump);
}
