#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int*b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int* arr, int low, int high) {
    int pivot = arr[low], i = low, j = high;
    // printf("\n");
    // printf("low: %d, high: %d", i, j);
    // printf("\n");
    while(i<j) {
        // find the index of the first element which is greater than the pivot (arr[low]) from left
        while(i<=high && pivot >= arr[i]) i++;
        //find the index of the first element which is smaller than the pivot (arr[low]) from the right
        while(j>=low && pivot < arr[j]) j--;
        // printf("I: %d, J: %d\n", i, j);
        if(i<j) {
            // printf("swapping i: %d, j: %d\n", i, j);
            swap(&arr[i], &arr[j]);
        }
    }
    // for(int i=0; i<=high; i++) printf("%d ", arr[i]);
    // printf("\n");
    swap(&arr[low], &arr[j]);
    // for(int i=0; i<=high; i++) printf("%d ", arr[i]);
    // printf("\n");
    return j;
}

void quick_sort(int* arr, int low, int high) {
    if(low<high) {
        //partition() -> finds the correct index for the pivot (arr[low])
        int Piv_ind = partition(arr, low, high);
        quick_sort(arr, low, Piv_ind-1);
        quick_sort(arr, Piv_ind+1, high);
        return;
    }
}


int main() {
    int n;
    scanf("%d", &n);
    int* a = (int*) malloc (sizeof(int)*n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);

    // quick sort->

    // here we take some pivot index
    // and place smaller elements on the left side of it
    // and place the larger element on the right side of it
    quick_sort(a, 0, n-1);
    printf("\n");
    for(int i=0; i<n; i++) printf("%d ", a[i]);
    printf("\n");
    

    
    return 0;
}