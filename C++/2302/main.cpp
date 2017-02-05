// you can use includes, for example:
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <set>
#define MAX 41
using namespace std;

int cache[MAX];

int main(void) {
    cache[0] = 1;
    cache[1] = 1;
    for(int i = 2; i < MAX; i++) {
        cache[i] = cache[i-1] + cache[i-2];
    }
    int n;
    scanf("%d", &n);
    int m;
    scanf("%d", &m);
    vector<int> vip;
    vip.push_back(0);
    for(int i = 0; i < m; i++) {
        int v;
        scanf("%d", &v);
        vip.push_back(v);
    }
    vip.push_back(n+1);
    int ans = 1;
    for(int i = 0; i < vip.size()-1; i++) {
        ans *= cache[vip[i+1] - vip[i] - 1];
    }
    cout << ans << "\n";
}


