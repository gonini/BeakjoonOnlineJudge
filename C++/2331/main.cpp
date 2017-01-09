#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define MAX 1000000

int next(int num);
void search(int v, int cnt);

using namespace std;

int isVisit[MAX];
int a, p;
int main(void){
    memset(isVisit, -1, sizeof(isVisit));
    scanf("%d %d", &a, &p);
    search(a, 1);
}

int next(int num) {
    if (num == 0) {
        return 0;
    }
    int here = num % 10;
    if (here > 0) {
        here = pow(here, p);
    }
    return here + next(num / 10);
}

void search(int v, int cnt) {
    if (isVisit[v] > -1) {
        printf("%d", isVisit[v] - 1);
        return;
    }
    isVisit[v] = cnt;
    search(next(v), cnt + 1);
}
