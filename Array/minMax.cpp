// Problem: Find minimum and maximum element in an array

#include <bits/stdc++.h>
using namespace std;

// time complexity: O(nlogn)
pair<long long, long long> solution1(long long arr[], int n) {
    sort(arr, arr + n);
    
    return {arr[0], arr[n - 1]}; 
}

// time complexity: O(n)
pair<long long, long long> solution2(long long arr[], int n) {
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

    pair <long long, long long> res1 = solution1(arr, n);
    pair <long long, long long> res2 = solution2(arr, n);

    cout << res1.first << ' ' << res1.second << endl;
    cout << res2.first << ' ' << res2.second;
}
