#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define MAX 42

pair<int,int> d[MAX+2];

int main(void){
    d[0] = make_pair(1,0);
    d[1] = make_pair(0,1);
    d[2] = make_pair(1,1);
    for(int i = 3; i < MAX; i++) {
        d[i] = make_pair((d[i-1].first + d[i-2].first) ,d[i-1].second + d[i-2].second);
    }
    
    int a, n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d",&a);
        printf("%d %d\n",d[a].first,d[a].second);
    }
}
