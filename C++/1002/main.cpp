#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int main(void){
    int t;
    scanf("%d", &t);
    while (t--) {
        int x1, y1, r1, x2, y2, r2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        double d = sqrt(((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
        double rSum = r1 + r2;
        double rDif = abs(r1 - r2);
        int ret = 0;
        
        if (x1 == x2 && y1 == y2 && r1 == r2) {
            ret = -1;
        } else if (rDif == d || rSum == d) {
            ret = 1;
        } else if (rDif < d && d < rSum) {
            ret = 2;
        }
        
        printf("%d\n", ret);
    }
}
