// Problem: Search element in an array

#include <iostream>
using namespace std;

int search(int arr[], int N, int X) {
    for (int i = 0; i < N; i++) {
        if (arr[i] == X) {
            return i;
        }
    }

    return -1;
}

int main() {
    int n, x; 
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << search(arr, n, x);
}
