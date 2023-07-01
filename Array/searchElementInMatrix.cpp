// Problem: Search element in a matrix

#include <iostream>
#include <vector>
using namespace std;

// time: O(m * n)
bool method1(vector<vector<int>>& matrix, int target) {
    int row = matrix.size(), col = matrix[0].size();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == target)
                return true;
        }
    }

    return false; 
}

// time: O(log(mn))
bool method2(vector<vector<int>>& matrix, int target) {
    int row = matrix.size(), col = matrix[0].size();
    int low = row - 1, high = 0;

    while (low >= 0 && high < col) {
        if (matrix[low][high] == target) {
            return true;
        } else if (matrix[low][high] < target) {
            high++;
        } else {
            low--;
        }
    }

    return false; 
}

int main() {
    int m, n; cin >> m >> n;
    vector<vector<int, int>> arr;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    int target; cin >> target;

    cout << method1(arr, target);
    cout << method2(arr, target);
}
