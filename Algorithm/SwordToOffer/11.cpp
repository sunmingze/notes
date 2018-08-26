/*
 * 1. 一个未排序数组 一个数组是否在数组中
 * */
#include <iostream>
#include <vector>

using namespace std;

template <class T>
void display (vector<T> v) {
    for (T item : v) {
        cout << item << " ";
    }
    cout << endl;
}

void mqsort(vector<int> &v, int l, int r) {
    if (l >= r || v.size() == 0) {
        return;
    }
    int key = v[l], i = l, j = r;
    while (i < j) {
        while (i < j && v[j] > key) { --j; }
        v[i] = v[j];
        while (i < j && v[i] <= key) { ++i; }
        v[j] = v[i];
    }
    v[i] = key;

    mqsort(v, l, i-1);
    mqsort(v, i+1, r);
    return;
}

int binarySearch(vector<int> v, int k) {
    int l = 0, r = v.size() - 1;
    while (l <= r) {
        int mid = (r - l) / 2 + l;
        if (k == v[mid]) {
            return mid;
        } else if (k < v[mid]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int leftBoundary (vector<int> v, int k) {
    int l = 0, r = v.size() - 1;
    while (l <= r) {
        int mid = (r - l) / 2 + l;
        if (v[mid] == k && (mid == 0 || v[mid-1] != k)) {
            return mid;
        } else if (v[mid] < k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    } 
    return -1;
}

int rightBoundary (vector<int> v, int k) {
    int l = 0, r = v.size() - 1;
    while (l <= r) {
        int mid = (r - l) / 2 + l;
        if (v[mid] == k && (mid == v.size()-1 || v[mid+1] != k)) {
            return mid;
        } else if (v[mid] > k) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
}

void displayRes (vector<int> v, int res) {
    if (v.size() == 0) {
        cout << "EMPTY VECTOR" << endl;
        return;
    }
    if (res >= 0) {
        cout << "FIND: " << v[res] << "  INDEX: " << res << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }
}

int main() {
    vector<int> e = {};
    vector<int> o = {0};
    vector<int> v = {1, 10, 3, 2, 7, 8, 18, 2, -1, 0, 0, 3, 2, 10, 22};
    display(v);

    // quick sort
    mqsort(v, 0, v.size() - 1);
    mqsort(e, 0, e.size() - 1);
    mqsort(o, 0, o.size() - 1);
    display(v);
    display(e);
    display(o);
    cout << "END QSORT" << endl;

    // binary search
    int res = binarySearch(v, 8);
    displayRes(v, res);
    res = binarySearch(v, -100);
    displayRes(v, res);
    res = binarySearch(e, -100);
    displayRes(e, res);
    res = binarySearch(o, -100);
    displayRes(o, res);
    displayRes(o, binarySearch(o, 0));
    cout << "END BINARY SEARCH" << endl << endl;

    // find left boundary
    res = leftBoundary(v, 2);
    displayRes(v, res);
    displayRes(o, leftBoundary(o, 0));
    displayRes(e, leftBoundary(e, 0));

    // find right boundary
    res = rightBoundary(v, 2);
    displayRes(v, res);
    
    return 0;
}
