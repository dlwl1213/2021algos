#include <iostream>

using namespace std;

void merge(int* arr, int* sortedArr, int start, int middle, int end) {
    int sortedInd = start;
    int i = start;
    int j = middle+1;

    while (i <= middle && j <= end) {
        if (arr[i] < arr[j]) sortedArr[sortedInd] = arr[i++];
        else  sortedArr[sortedInd] = arr[j++];

        sortedInd++;
    }

    if (i > middle) {
        while (j <= end) {
            sortedArr[sortedInd++] = arr[j++];
        }
    }

    if (j > end) {
        while (i <= middle) {
            sortedArr[sortedInd++] = arr[i++];
        }
    }

    for (int k = start; k <= end; k++) arr[k] = sortedArr[k];

}

void mergeSort(int* arr, int* sortedArr, int begin, int end) {
    int m;
    if (begin<end) {
        m = (begin + end) / 2;
        mergeSort(arr, sortedArr, begin, m);
        mergeSort(arr, sortedArr, m + 1, end);
        merge(arr, sortedArr, begin, m, end);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int* sortedArr = new int[n];
    mergeSort(arr, sortedArr, 0, n-1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';

    return 0;
}
