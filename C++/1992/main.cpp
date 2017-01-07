#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAX 65

using namespace std;

int tree[MAX][MAX];

bool same(int x, int y, int n){
    for(int i = x; i < x + n; i++){
        for(int j = y; j < y + n; j++){
            if(tree[x][y] != tree[i][j]){
                return false;
            }
        }
    }
    return true;
}

void solve(int x, int y, int n){
    if(same(x, y, n)){
        printf("%d", tree[x][y]);
    } else {
        printf("(");
        int m = n / 2;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                solve(x + i * m, y + j * m, m);
            }
        }
        printf(")");
    }
}


int main(void){
    
    memset(tree, 0, sizeof(tree));
    int n;
    scanf("%d\n", &n);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%1d", &tree[i][j]);
        }
    }
    
    solve(0, 0, n);
}
