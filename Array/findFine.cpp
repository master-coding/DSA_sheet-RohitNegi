// Problem: Find fine

#include <iostream>
using namespace std;

long long int totalFine(int n, int date, int car[], int fine[]) {
    long long evenFine = 0, oddFine = 0;
    for (int i = 0; i < n; i++) {
        if (car[i] % 2 == 0) evenFine += fine[i];
        else oddFine += fine[i];
    }
    
    if (date % 2 == 0) return oddFine;
    
    return evenFine;
}


int main() {
    int n, i, date;
    cin >> n >> date;
    int car[n], fine[n];
    
    for (i = 0; i < n; i++) cin >> car[i];
    for (int i = 0; i < n; i++) cin >> fine[i];

    cout << totalFine(n, date, car, fine) << endl;
}
