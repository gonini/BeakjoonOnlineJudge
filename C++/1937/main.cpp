// you can use includes, for example:
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <set>
#define MAX 501
using namespace std;

int cache[MAX][MAX];
int forest[MAX][MAX];
int ax[4] = {0, 0, 1, -1};
int ay[4] = {1, -1, 0, 0};
int n;

int move(int x, int y);

int main(void) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &forest[i][j]);
        }
    }
    memset(cache, 0, sizeof(cache));
    int maximumLife = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            maximumLife = max(maximumLife, move(i, j));
        }
    }
    cout << maximumLife << "\n";
    
}

int move(int x, int y) {
    if(!(0 <= x && 0 <= y && x < n && y < n)) {
        return 0;
    }
    int& ret = cache[x][y];
    if(ret != 0) {
        return ret;
    }
    ret = 1;
    for(int i = 0; i < 4; i++) {
        int mx = x + ax[i];
        int my = y + ay[i];
        if(forest[x][y] < forest[mx][my]) {
            ret = max(ret, move(mx, my) + 1);
        }
    }
    return ret;
}

