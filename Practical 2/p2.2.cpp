#include <iostream>
#include <vector>
using namespace std;

int binarySearchIterative(const vector<int>& codes, int target) {
    int low = 0;
    int high = static_cast<int>(codes.size()) - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (codes[mid] == target) {
            return mid;
        } else if (codes[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int binarySearchRecursive(const vector<int>& codes, int target, int low, int high) {
    if (low > high) {
        return -1
    }
    int mid = low + (high - low) / 2;
    if (codes[mid] == target) {
        return mid;
    } else if (codes[mid] < target) {
        return binarySearchRecursive(codes, target, mid + 1, high);
    } else {
        return binarySearchRecursive(codes, target, low, mid - 1);
    }
}

    