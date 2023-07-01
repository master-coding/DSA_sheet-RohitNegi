// Problem: 

#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}

void solution(int arr[], int n) {
    int lastElement = arr[n - 1];

    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = lastElement;
    
    printArray(arr, n);
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    solution(arr, n);
}
