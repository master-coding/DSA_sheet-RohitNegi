// Problem: Greater on right side

#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}

void solution(int arr[], int n) {
    int temp[n];
    temp[n - 1] = -1;
    
    int largest = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        temp[i] = largest;
        largest = max(largest, arr[i]);
    }
    
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];

    printArray(arr, n);
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    solution(arr, n);
}
