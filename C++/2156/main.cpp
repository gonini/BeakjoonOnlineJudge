#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

#define MAX 10003
#define RANGE_OUT (1<<31)

using namespace std;

int a[MAX];
int d[MAX];
int toDrink(int idx);
int main() {
    
    memset(a, 0, sizeof(a));
    memset(d, -1, sizeof(d));
    
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int ret = 0;
    for(int i = 0; i < n; i++) {
        ret = max(ret, toDrink(i));
    }
    
    printf("%d", ret);
    
    return 0;
}

int toDrink(int i) {
    if (i < -1) {
        return RANGE_OUT;
    }
    int &cache = d[i];
    if (i == 0) {
        return cache = a[i];
    }
    if (cache != -1) {
        return cache;
    }
    int oneTimeInRow = max(toDrink(i-2) + a[i], a[i]);
    int twoTimeInRow = max(toDrink(i-3) + a[i-1] + a[i], a[i-1] + a[i]);
    
    return cache = max(d[i-1], max(oneTimeInRow, twoTimeInRow));
}
