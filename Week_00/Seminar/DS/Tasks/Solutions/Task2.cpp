#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    for(int i = v.size() - 1; i >= 0; i--) {
        v[i] += 1;
        if(v[i] < 10) {
            break;
        }
        
        v[i] = 0;
    }
    
    if(v[0] == 0) {
        v.insert(v.begin(), 1);
    }
    
    for(auto it = v.begin(); it != v.end(); it++)
        cout << *it;
  
    return 0;
}
