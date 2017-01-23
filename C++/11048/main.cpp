#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define MAX 1001
#define RANGE_OUT (1<<31)

using namespace std;
int biggestSweets(int x, int y);

int n, m;
int maze[MAX][MAX];
int cache[MAX][MAX];

int main(void) {
    scanf("%d %d", &n, &m);
    memset(maze, 0, sizeof(maze));
    memset(cache, -1, sizeof(cache));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    
    printf("%d\n", biggestSweets(1, 1));
}

int biggestSweets(int x, int y) {
    if(!(n >= x && m >= y)) {
        return RANGE_OUT;
    }
    int& here = cache[x][y];
    if(here != -1) {
        return here;
    }
    if(x == n && y == m) {
        return here = maze[x][y];
    }
    int biggest = maze[x][y] + max(biggestSweets(x, y + 1), biggestSweets(x + 1, y));
    return here = biggest;
}
