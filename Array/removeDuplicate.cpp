// Problem: Remove duplicate elements from sorted Array

#include <iostream>
using namespace std;

int remove_duplicate(int arr[],int n){
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[count]) {
            arr[++count] = arr[i];
        }
    }
    
    return count + 1;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << remove_duplicate(arr, n);
}
