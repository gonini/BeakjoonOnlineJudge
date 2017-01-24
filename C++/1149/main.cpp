#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

int a[3];
int d[3];
int k[3];

int rgb(int n, int idx);

int main(void) {
    memset(a, 0, sizeof(a));
    memset(d, 0, sizeof(d));
    
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < 3; i++) {
        scanf("%d", &a[i]);
        d[i] = a[i];
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            
            scanf("%d", &a[j]);
            int idx1 = j-1;
            int idx2 = j+1;
            
            if(idx1 == -1) {
                idx1 = 2;
            }
            if(idx2 == 3) {
                idx2 = 0;
            }
            
            k[j] = a[j] + min(d[idx1], d[idx2]);
        }
        for(int j = 0; j < 3; j++) {
            d[j] = k[j];
        }
    }
 
    int ans = ~(1<<31);
    for(int i = 0; i < 3; i++) {
        ans = min(ans, d[i]);
    }
    printf("%d\n", ans);
}
