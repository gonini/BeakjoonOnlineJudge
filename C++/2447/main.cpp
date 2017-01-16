#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#define MAX 6500
#define BLANK 0
#define STAR 1

using namespace std;

char a[MAX][MAX];

void solve(int x, int y, int n, int plag){
    if(plag == BLANK){
        for(int i = x; i < x+n; i++){
            for(int j = y; j < y+n; j++){
                a[i][j] = ' ';
            }
        }
    } else {
        if(n == 1) {
            a[x][y] = '*';
        } else {
            int m = n/3;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(i == 1 && j == 1){ // BLANK
                        solve(x + i * m, y + j * m, m, BLANK);
                    } else {
                        solve(x + i * m, y + j * m, m, STAR);
                    }
                }
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    
    solve(0, 0, n, STAR);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
