// Problem: Sort an array of 0s, 1s and 2s

#include <iostream>
using namespace std;

// time: O(n), 2 traversals
void mt1(int arr[], int n) {
    int zeroes = 0, ones = 0, twos = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) zeroes++;
        else if (arr[i] == 1) ones++;
        else twos++;
    }
    
    int j = 0;
    while (zeroes--) arr[j++] = 0;
    while (ones--) arr[j++] = 1;
    while (twos--) arr[j++] = 2;
}

// time: O(n) 1 traversal
// DUTCH NATIONAL FLAG ALGORITHM
void mt2(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low++], arr[mid++]);
            
        } else if (arr[mid] == 2) {
            swap(arr[mid], arr[high--]);
        } else {
            mid++;
        }
    }
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    // mt1(arr, n);
    mt2(arr, n);
}
