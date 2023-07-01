// Problem: Binary Array Sorting

#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    
    cout << '\n';
}

// time: O(n), space: O(n)
void mt1(int arr[], int n) {
    int temp[n];
    int left = 0, right = n - 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            temp[left++] = 0;   
        } else {
            temp[right--] = 1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    printArray(arr, n);
}

// time: O(n), space: O(1)
void mt2(int arr[], int n) {
    int zeroes = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            swap(arr[i], arr[count++]);
        }
    }

    printArray(arr, n);
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    mt1(arr, n);
    mt2(arr, n);
}
