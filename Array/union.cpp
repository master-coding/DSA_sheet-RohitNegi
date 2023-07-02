// Problem: 

#include <iostream>
#include <vector>
using namespace std;

vector<int> findUnion1(int arr1[], int arr2[], int n, int m) {
    vector <int> res;
    int i = 0, j = 0;
    
    while (i < n && j < m) {
        // incrementing i and j if the next element is same
        while (i + 1 < n && arr1[i] == arr1[i + 1]) i++;
        while (j + 1 < m && arr2[j] == arr2[j + 1]) j++;
        
        if (arr1[i] < arr2[j]) res.push_back(arr1[i++]);
        else if (arr1[i] > arr2[j]) res.push_back(arr2[j++]);
        else {
            res.push_back(arr1[i++]);
            j++;
        }
    }
    
    while (i < n) {
        while (i + 1 < n && arr1[i] == arr1[i + 1]) i++;

        res.push_back(arr1[i++]);
    }
    while (j < m) {
        while (j + 1 < m && arr2[j] == arr2[j + 1]) j++;
        
        res.push_back(arr2[j++]);
    }        
    
    return res;
}
    
vector<int> findUnion2(int arr1[], int arr2[], int n, int m) {
    vector <int> res;
    set <int> s;
    int first = 0, second = 0;
    
    while (first < n && second < m) {
        if (arr1[first] < arr2[second]) {
            s.insert(arr1[first++]);
        } else if (arr1[first] > arr2[second]) {
            s.insert(arr2[second++]);
        } else {
            s.insert(arr1[first++]);
            second++;
        }
    }
    
    while (first < n) s.insert(arr1[first++]);
    while (second < m) s.insert(arr2[second++]);
    
    for (auto &unique: s) {
        res.push_back(unique);
    }
    
    
    return res;
}

int main() {
    int n, m; cin >> n >> m;
    int arr1[n], arr2[m];
    
    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < m; i++) cin >> arr2[i];
}
