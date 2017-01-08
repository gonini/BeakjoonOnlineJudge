#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

bool isIncludCircle(int cx, int cy, int r, int x, int y);

int main(void){
    int t;
    scanf("%d", &t);
    while (t--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        int n;
        int ret = 0;
        scanf("%d", &n);
        while(n--) {
            int cx, cy, r;
            scanf("%d %d %d", &cx, &cy, &r);
            double d1 = sqrt((cx - x1) * (cx - x1) + (cy - y1) * (cy - y1));
            double d2 = sqrt((cx - x2) * (cx - x2) + (cy - y2) * (cy - y2));
            if ((d1 < r || d2 < r) && !(d1 < r && d2 < r)) {
                ret += 1;
            }
        }
        printf("%d\n", ret);
    }
}
