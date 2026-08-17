#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];

    cout << "Enter colour codes (0, 1, 2): ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int low = 0, mid = 0, high = n - 1;

    while(mid <= high) {
        if(a[mid] == 0) {
            int temp = a[low];
            a[low] = a[mid];
            a[mid] = temp;
            low++;
            mid++;
        }
        else if(a[mid] == 1) {
            mid++;
        }
        else {
            int temp = a[mid];
            a[mid] = a[high];
            a[high] = temp;
            high--;
        }
    }

    cout << "Sorted colour codes: ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
