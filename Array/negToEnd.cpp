// Problem: Move all negative elements to end

#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }

    cout << '\n';
}

// 2 traversals, auxillary space: O(n)
void mt1(int arr[], int n) {
    vector <int> pos, neg;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            neg.push_back(arr[i]);
        } else {
            pos.push_back(arr[i]);
        }
    }
    
    for (int i = 0; i < pos.size(); i++) {
        arr[i] = pos[i];
    }
    for (int j = 0; j < neg.size(); j++) {
        arr[j + pos.size()] = neg[j];
    }

    printArray(arr, n);
}

// 3 traversals, auxillary space: O(n)
void mt2(int arr[], int n) {
    int count = 0, temp[n];
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) count++;
    }
    
    int pos = 0, neg = count;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            temp[neg++] = arr[i];
        } else {
            temp[pos++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    printArray(arr, n);
}

// 3 traversals, auxillary space: O(n)
void mt3(int arr[], int n) {
    int temp[n], j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0)
            temp[j++] = arr[i];
    }

    // if all are pos or all neg
    if (j == n || j == 0)
        return;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0)
            temp[j++] = arr[i];
    }

    for (int i = 0; i < n; i++)
        arr[i] = temp[i];

    printArray(arr, n);
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    // mt1(arr, n);
    // mt2(arr, n);
    mt3(arr, n);
}
