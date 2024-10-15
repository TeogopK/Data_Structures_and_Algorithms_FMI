#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v;
    
    for(int i = 0; i < n; i++) {
        pair<int, int> p;
        cin >> p.first;
        p.second = i;
        v.push_back(p);
    }
    
    sort(v.begin(), v.end());
    
    int beg = 0;
    int end = v.size() - 1;
    
    while(beg != end) {
        int currSum = v[beg].first + v[end].first;
        
        if(currSum == k) {
            cout << v[beg].second << " " << v[end].second;
            break;
        }
        
        if(currSum > k) 
            end--;
        else
            beg++;
    }
    
    return 0;
}
