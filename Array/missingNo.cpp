// Problem: Missing number

#include <iostream>
using namespace std;

// time : O(n), space: O(n)
int method1(int arr[], int N) {
    int missing[N] = {0};
    
    for (int i = 0; i < N - 1; i++) {
        missing[arr[i] - 1]++;
    }
    
    for (int i = 0; i < N; i++) {
        if (missing[i] == 0)
            return i + 1;
    }
    
    return -1;
}

// time: O(n) space: O(1)
int method2(int arr[], int N) {
    int missing = 0;
    for (int i = 1; i <= N; i++) missing ^= i;
    for (int i = 0; i < N - 1; i++) missing ^= arr[i];

    return missing;
}

// time: O(n) space: O(1)
int method3(int A[], int N) {
    int sum=0;
    for(int i = 0; i < N - 1; i++)
		sum += A[i];

	return ((N*(N+1))/2) - sum;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n - 1; i++) cin >> arr[i];

    // cout << method1(arr, n);
    cout << method2(arr, n);
    // cout << method3(arr, n);
}
