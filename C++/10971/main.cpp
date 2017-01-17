#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#define MAX 5001

using namespace std;

int adj[MAX][MAX];
vector<int> path;

int main() {
    ios::sync_with_stdio(false);
    memset(adj, 0, sizeof(adj));
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> adj[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        path.push_back(i);
    }
    
    int ans = ~(1<<31);
    
    do {
        bool isPossible = true;
        int sum = 0;
        for(int i = 1; i < path.size(); i++){
            int cost = adj[path[i-1]][path[i]];
            if(0 != cost){
                sum += cost;
            } else {
                isPossible = false;
                break;
            }
        }
        
        if(isPossible && adj[path[n-1]][path[0]] != 0){
            sum += adj[path[n-1]][path[0]];
            ans = min(ans, sum);
        }
        
    } while(next_permutation(path.begin()+1, path.end()));
    
    cout << ans << "\n";
    return 0;
}
