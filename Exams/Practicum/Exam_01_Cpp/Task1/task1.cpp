#include <bits/stdc++.h>

using namespace std;

int main() {
    
    vector<int>counts(255, 0);
    
    string s;
    cin>>s;
    
    for (const auto& letter : s) {
        counts[letter]++;
    }
    
    int odds = 0;
    for (const auto& count : counts) {
        if (count % 2 == 1) odds++;
    }

    if (odds <= 1) {
        cout<<0;
    } else {
        cout<<odds-1;
    }
    
    return 0;
}