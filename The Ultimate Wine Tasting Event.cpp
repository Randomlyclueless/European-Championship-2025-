#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int redInFirstHalf = 0;
    
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') redInFirstHalf++;
    }


    if (redInFirstHalf <= n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;  
    while (t--) {
        solve();
    }
    return 0;
}
