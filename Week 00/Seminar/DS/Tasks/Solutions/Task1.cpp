#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() { 
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == k)
        {
            v.erase(v.begin() + i);
            i--;
        }
    }
  
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}
