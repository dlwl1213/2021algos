#include <stdio.h>
#include <stdlib.h>

typedef struct { //점의 좌표를 구조체로 선언
    int x;
    int y;
} point;

point sort_arr[100001]; //정렬이 일어날 배열 sort_arr

void merge(point* arr, int first, int mid, int last) {
    int i, j, k;
    i = first;
    j = mid + 1;
    k = first;

    while (i <= mid && j <= last) {
        if (arr[i].x < arr[j].x)
            sort_arr[k++] = arr[i++];
        else if (arr[i].x > arr[j].x)
            sort_arr[k++] = arr[j++];
        else {
            if (arr[i].y < arr[j].y)
                sort_arr[k++] = arr[i++];
            else if (arr[i].y > arr[j].y)
                sort_arr[k++] = arr[j++];
        }
    }

    if (i <= mid) {
        while (i <= mid) 
            sort_arr[k++] = arr[i++];
    }
    else {
        while (j <= last) 
            sort_arr[k++] = arr[j++];
    }
    for (k = first; k <= last; k++)
        arr[k] = sort_arr[k];
}

void mergesort(point* arr, int first, int last) {
    int mid;
    if (first < last) {
        mid = (first + last) / 2;
        mergesort(arr, first, mid);
        mergesort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    point* arr = (point*)malloc(sizeof(point)*n);
    for(int i = 0; i < N; i++)
        scanf("%d %d", &arr[i].x, &arr[i].y);
    
    mergesort(arr, 0, N-1);
    for (int i = 0; i < N; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);

    return 0;
}
