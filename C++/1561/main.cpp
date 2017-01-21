#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define MAX 1000002
using namespace std;

long long n, m;
int Rides[MAX];

long long clacOnBorad(long long min){
    long long end = m;
    for(int i = 1; i <= m; i++){
        end += min/Rides[i];
        if(min < i) break;
    }
    
    if(end < n) return 0;
    long long curCnt = 0;
    vector<int> ridesIdx;
    for(int i = 1; i <= m; i++){
        if(min % Rides[i] == 0){
            curCnt+=1;
        }
    }
    long long begin = end-curCnt+1;
    if(begin > n) return -1;
    
    for(int i=1; i<=m; i++){
        if(min%Rides[i] == 0){
            if(begin == n){
                return i;
            }
            begin++;
        }
    }
    
    return begin;
}

long long sovle(long long l, long long r){
    if(l > r) return 0;
    long long mid = (l+r)/2;
    long long ridesIdx = clacOnBorad(mid);
    if(ridesIdx == 0){
        return sovle(mid+1, r);
    } else if(ridesIdx == -1) {
        return sovle(l, mid - 1);
    } else {
        return ridesIdx;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    memset(Rides, 0, sizeof(Rides));
    for(int i = 1; i <= m; i++){
        cin >> Rides[i];
    }
    if (n <= m) {
        cout << n << "\n";
        return 0;
    }
    
    cout << sovle(0, 2000000000LL * 1000000LL) << "\n";
    return 0;
}

