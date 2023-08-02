#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

// ---------  Quick Sort ----------------

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// -------------- Quick Sort ---------------

// -------------- Merge Sort ---------------

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for(j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        k++;
        i++;
    }
    while(j < n2){
        arr[k] = R[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}



// -------------- Merge Sort ---------------



void printArray(int arr[], int n){
    printf("The sorted array is:\n");
    for(int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void sort(){
    int choice, n;
    int arr[50];
    printf("Enter the number of numbers you wish to enter: ");
    scanf("%d", &n);
    printf("Enter the numbers: \n");
    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    printf("Select your sorting method:\n");
    printf("1. Merge Sort\n");
    printf("2. Quick Sort\n");
    scanf("%d", &choice);
    switch(choice){
        case 1: mergeSort(arr, 0, n -1);
                printArray(arr, n);
                break;
        case 2: quickSort(arr, 0, n -1);
                printArray(arr, n);
                break;
        default: printf("Invalid input!\n");
                break;
    }
}

int main(){
    int choice;
    while(1){
        printf("1. Sort numbers:\n");
        printf("2. Exit\n");
        scanf("%d", &choice);
        if(choice == 1)
            sort();
        else if(choice == 2)
            exit(0);
        else
            printf("Invalid input!\n");
    }


    return 0;
}
