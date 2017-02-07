#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    
    for(int i = 0; i < n; i++){
        a[i] = i+1;
    }
    
    do{
        for(int i = 0; i < a.size(); i++){
            cout << a[i] << " ";
        }
        cout << "\n";
    } while (next_permutation(a.begin(), a.end()));
    
}

