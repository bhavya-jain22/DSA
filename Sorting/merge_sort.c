#include<stdio.h>
#include<stdlib.h>


void merge(int* arr, int low, int mid, int high) {
    int i=low, j = mid+1, ind = 0;
    int* temp = (int*) malloc (sizeof(int)*(high-low+1));
    while(i<=mid && j<=high) {
        if(arr[i]<=arr[j]) {
            temp[ind] = arr[i];
            i++;
            ind++;
        }
        else {
            temp[ind] = arr[j];
            j++;
            ind++;
        }
    }
    while(i<=mid) {
        temp[ind] = arr[i];
        ind++;
        i++;
    }
    while(j<=high) {
        temp[ind] = arr[j];
        ind++;
        j++;
    }

    for(int i=low; i<=high; i++) {
        arr[i] = temp[i-low];
    }
    free(temp);
}

void merge_sort(int* arr, int low, int high) {
    if(low>=high) return;
    int mid = low + (high-low)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);

}


int main () {

    int n; 
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);

    //merge sort ->
    // Here we divide the array into two halves untill we are remaining with only one-one element
    // (since one element is always sorted).
    // now we will merge those elements in such a way that the merged array(temp) is sorted.
    merge_sort(a, 0, n-1);
    for(int i=0; i<n; i++) printf("%d ", a[i]);
    free(a);
    
return 0;
}