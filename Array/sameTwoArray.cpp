// Problem: 

#include <bits/stdc++.h>
#include <vector>

#define ll long long

using namespace std;

// time complexity: O(nlogn)
bool solution1(vector <ll> a, vector <ll> b, int n) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return a == b;
}

// time complexity: O(n), auxillary space: O(n)
bool solution2(vector<ll> a, vector<ll> b, int n) {
    map <ll, int> m;
    for (int i = 0; i < n; i++) m[a[i]]++;
    for (int i = 0; i < n; i++) m[b[i]]--;
    
    for (auto value: m) {
        if (value.second != 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n; cin >> n;
    vector <ll> a(n, 0), b(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    cout << solution2(a, b, n);
}
