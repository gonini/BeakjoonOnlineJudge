#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define UNCOVER -1
#define MAX 2001
int seq[MAX];
int cache[MAX][MAX];
int isPalindrome(int s, int e);

int main(void) {
    memset(cache, UNCOVER, sizeof(cache));
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &seq[i]);
    }
    int m;
    int s, e;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);
        printf("%d\n", isPalindrome(s, e));
    }
}

int isPalindrome(int s, int e) {
    if(e < s) {
        return 1;
    }
    if(s == e) {
        return 1;
    }
    int &here = cache[s][e];
    if(here != UNCOVER) {
        return here;
    }
    return here = (seq[s] == seq[e]) && isPalindrome(s + 1, e - 1);
}
