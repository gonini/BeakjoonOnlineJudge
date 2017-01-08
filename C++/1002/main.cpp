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
        double distance = sqrt(((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
        double rSum = r1 + r2;
        double rDiffer = abs(r1 - r2);
        int ret = 0;
        
        if (x1 == x2 && y1 == y2 && r1 == r2) {
            ret = -1;
        } else if (rDiffer == distance || rSum == distance) {
            ret = 1;
        } else if (rDiffer < distance && distance < rSum) {
            ret = 2;
        } else{
            ret = 0;
        }
        printf("%d\n", ret);
    }
}
