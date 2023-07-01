// Problem: Find minimum and maximum element in an array

#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> solution(long long arr[], int n) {
    pair<long long, long long> res;
    long long minn = arr[0], maxx = arr[0];
    
    for (int i = 1; i < n; i++) {
        minn = min(minn, arr[i]);
        maxx = max(maxx, arr[i]);
    }
    
    res.first = minn;
    res.second = maxx;
    
    return res; 
}

int main() {
    int n; cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    pair <long long, long long> res = solution(arr, n);
    cout << res.first << ' ' << res.second;
}
