#include <bits/stdc++.h>

using namespace std;

long long merge(vector<int> &arr, int left, int mid, int right) {
    cout << "di dalam merge, nilai left: " << left << ", mid: " << mid << ", dan right: " << right << endl;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    long long inversions = 0;

    int left_array[n1];
    int right_array[n2];

    for (int i = 0; i < n1; i++) {
        left_array[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++) {
        right_array[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        cout << "di dalam while, nilai i: " << i << ", j: " << j << ", dan k: " << k << endl;
        if (left_array[i] <= right_array[j]) {
            arr[k] = left_array[i];
            i++;
        } else {
            cout << "masuk aloy, nilai i: " << i << ", j: " << j << ", dan k: " << k << ", dan nilai n1: " << n1 << ", dan nilai n1 - i: " << n1 - i << endl;
            inversions += (n1 - i);
            arr[k] = right_array[j];
            j++;
        }
        k++;
        cout << "akhir while, nilai i: " << i << ", j: " << j << ", dan k: " << k << endl << endl;
    }

    while (i < n1) {
        arr[k] = left_array[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right_array[j];
        j++;
        k++;
    }
    
    cout << "akhir merge, nilai left: " << left << ", mid: " << mid << ", dan right: " << right << ", dan nilai inversions: " << inversions << endl << endl;
    return inversions;
}

long long mergeSort(vector<int> &arr, int left, int right) {
    cout << "di dalam mergeSort, nilai left: " << left << " dan nilai right: " << right << endl;
    long long inversions = 0;
    if (left < right) {
        int mid = (left + right) >> 1;
        cout << "nilai mid: " << mid << endl;
        
        inversions += mergeSort(arr, left, mid);
        cout << "nilai inversions setelah mergeSort(arr, left, mid): " << inversions << endl;
        
        inversions += mergeSort(arr, mid + 1, right);
        cout << "nilai inversions setelah mergeSort(arr, mid + 1, right): " << inversions << endl;
        
        inversions += merge(arr, left, mid, right);
        cout << "nilai inversions setelah merge(arr, left, mid, right): " << inversions << endl << endl;
    }
    return inversions;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long inversions = mergeSort(arr, 0, n - 1);
    
    cout << inversions << endl;
}