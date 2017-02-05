// you can use includes, for example:
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <set>
#define MAX 100001
using namespace std;

int cache[MAX][3];

int main(void) {
    int n;
    scanf("%d", &n);
    memset(cache, 0, sizeof(cache));
    for(int i = 0; i < 3; i++) {
        cache[0][i] = 1;
    }
    
    for(int i = 1; i < n; i++) {
        cache[i][0] = cache[i-1][0] + cache[i-1][1] + cache[i-1][2];
        cache[i][1] = cache[i-1][0] + cache[i-1][2];
        cache[i][2] = cache[i-1][0] + cache[i-1][1];
        for(int j = 0; j < 3; j++) {
            cache[i][j] %= 9901;
        }
    }
    
    cout << (cache[n-1][0] + cache[n-1][1] + cache[n-1][2]) % 9901 << "\n";
}

