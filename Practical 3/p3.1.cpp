#include <iostream>
using namespace std;

void print(int a[], int n) {
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void bubbleSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min = i;

        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[min])
                min = j;
        }

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void insertionSort(int a[], int n) {
    for(int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    int a[n], b[n], c[n], d[n];

    cout << "Enter marks: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        c[i] = a[i];
        d[i] = a[i];
    }

    bubbleSort(b, n);
    selectionSort(c, n);
    insertionSort(d, n);

    cout << "\nBubble Sort: ";
    print(b, n);

    cout << "Selection Sort: ";
    print(c, n);

    cout << "Insertion Sort: ";
    print(d, n);

    return 0;
}
