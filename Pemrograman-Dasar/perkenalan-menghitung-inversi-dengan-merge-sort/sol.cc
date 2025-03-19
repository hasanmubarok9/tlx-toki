#include <bits/stdc++.h>

using namespace std;

long long merge(vector<int> &arr, int left, int mid, int right) {
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
        if (left_array[i] <= right_array[j]) {
            arr[k] = left_array[i];
            i++;
        } else {
            inversions += (n1 - i);
            arr[k] = right_array[j];
            j++;
        }
        k++;
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
    
    return inversions;
}

long long mergeSort(vector<int> &arr, int left, int right) {
    long long inversions = 0;
    if (left < right) {
        int mid = (left + right) >> 1;
        
        inversions += mergeSort(arr, left, mid);
        
        inversions += mergeSort(arr, mid + 1, right);
        
        inversions += merge(arr, left, mid, right);
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