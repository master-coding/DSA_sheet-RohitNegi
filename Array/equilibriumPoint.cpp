// Problem: Equilibruim Point

#include <iostream>
using namespace std;

// time: O(n)[3 traversals], space: O(n)
int method1(long long arr[], int n) {
    int prefixSum[n], suffixSum[n];
    
    prefixSum[0] = arr[0];
    suffixSum[n - 1] = arr[n - 1];
    
    for (int i = 1; i < n; i++) prefixSum[i] = prefixSum[i - 1] + arr[i];
    for (int i = n - 2; i >= 0; i--) suffixSum[i] = suffixSum[i + 1] + arr[i];
    
    if (suffixSum[0] - arr[0] == 0) return 1;
    if (prefixSum[n - 1] - arr[n - 1] == 0) return n;
    
    for (int i = 1; i < n - 1; i++) {
        if (prefixSum[i] - arr[i] == suffixSum[i] - arr[i])
            return i + 1;
    }
    
    return -1;
}

// time: O(n)[2 traversals], space: O(1)
int method2(long long arr[], int n) {
    long long total = 0;
    for (int i = 0; i < n; i++) total += arr[i];
    
    int leftSum = 0;
    for (int i = 0; i < n; i++) {
        total -= arr[i];
        if (total == leftSum)
            return i + 1;
            
        leftSum += arr[i];
    }
    
    return -1;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    // cout << method1(arr, n);
    cout << method2(arr, n);
}
