#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

void moveTo(int x, int y, int n);
int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", (1<<n) - 1);
    moveTo(1, 3, n);
}

void moveTo(int x, int y, int n) {
    if(n > 0) {
        moveTo(x, 6 - (x + y), n - 1);
        cout << x << " " << y << "\n";
        moveTo(6 - (x + y), y, n - 1);
    }
}
