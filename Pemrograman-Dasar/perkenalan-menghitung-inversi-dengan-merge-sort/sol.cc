#include <bits/stdc++.h>

using namespace std;

long long merge(vector<int>& a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> l(n1);
    vector<int> r(n2);

    for (int i = 0; i < n1; i++) {
        l[i] = a[left + i];
    }
    for (int j = 0; j < n2; j++) {
        r[j] = a[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    long long inversions = 0;

    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            a[k] = l[i];
            i++;
        } else {
            a[k] = r[j];
            j++;
            inversions += n1 - i;
        }
        k++;
    }

    while (i < n1) {
        a[k] = l[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = r[j];
        j++;
        k++;
    }

    return inversions;
    
}

long long mergeSort(vector<int>& a, int left, int right) {
    if (left >= right) {
        return 0;
    }

    int mid = (left + right) >> 1;
    long long inversions = 0;

    inversions += mergeSort(a, left, mid);
    inversions += mergeSort(a, mid + 1, right);
    inversions += merge(a, left, mid, right);

    return inversions;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long inversions = mergeSort(a, 0, n - 1);
    cout << inversions << endl;
}